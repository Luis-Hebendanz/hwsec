`timescale 1ns / 1ps
//
//module glob;
//
//// Constants
//parameter CLKS_TW = FREQ / BAUD_RATE;
//parameter FREQ = 32*10^6;
//parameter BAUD_RATE = 9600;
//
//endmodule


module top(
    input wire CLK,
	 input wire RX,
	 output wire TX,
	 output reg LED1,
	 output reg A4, // Reset
	 
	 // Gold
	 input wire A1, // TXD
	 output wire A0 // RXD
	 
    );
// Globals
reg rst = 0;



// ==== Gold Board =====
wire gold_valid;
wire [7:0] gold_data_rx;

uart_rx_sol gold_recv (
	.clk(CLK), 
	.rst(rst), 
	.din(A1), 
	.valid(gold_valid), // Set when received data is valid
	.data_out(gold_data_rx)
);

reg gold_en;
reg [7:0] gold_data_tx;
wire gold_rdy;
uart_tx_sol gold_tx (
	.clk(CLK),
	.rst(rst),
	.en(gold_en), // Enable bit (only set when rdy bit set)
	.data_in(gold_data_tx), // Data to transmit
	.rdy(gold_rdy), // Set when transmitter is ready to send again
	.dout(A0)
);


// ======== FPGA Uart ========
reg en = 0;
wire rdy;
reg [7:0] data_tx;
uart_tx_sol txi (
	.clk(CLK),
	.rst(rst),
	.en(en), // Enable bit (only set when rdy bit set)
	.data_in(data_tx), // Data to transmit
	.rdy(rdy), // Set when transmitter is ready to send again
	.dout(TX)
);

wire [7:0] data_rx;
wire valid;
uart_rx_sol rxi (
	.clk(CLK), 
	.rst(rst), 
	.din(RX), 
	.valid(valid), // Set when received data is valid
	.data_out(data_rx)
);

`define NORMAL 3'b000
`define FPGA_BUF_FULL 3'b001
`define GOLD_BUF_FULL 3'b010
`define NONE 3'b111

reg [2:0] state = `NORMAL;
reg [7:0] fpga_buf = 8'b0;
reg [7:0] gold_buf = 8'b0;

always @(posedge CLK)
begin

en <= 0; // disable fpga transmitter
gold_en <= 0; // disable gold transmitter
A4 <= 1;

case(state)
`NORMAL: begin
	if(gold_valid) // if fpga received data from gold board
	begin
		if(rdy) // Check if fpga transmitter is ready
		begin
			data_tx <= gold_data_rx; // Send data to pc
			en <= 1;
		end else
		begin
			fpga_buf <= gold_data_rx;
			state = `FPGA_BUF_FULL;
		end
	end
	
	if(valid) // If data received from pc
	begin
		if(gold_rdy) // if gold transmitter ready
		begin
			gold_data_tx <= data_rx; // send to gold board
			gold_en <= 1;
		end else
		begin
			gold_buf <= gold_data_rx;
			state = `GOLD_BUF_FULL;
		end
	end
end

`FPGA_BUF_FULL: begin
	if(rdy) // Check if fpga transmitter is ready
	begin
		data_tx <= fpga_buf; // Send data to pc
		en <= 1;
		state = `NORMAL;
	end 
end

`GOLD_BUF_FULL: begin
	if(gold_rdy) // Check if gold transmitter is ready
	begin
		gold_data_tx <= gold_buf; // Send data to gold
		gold_en <= 1;
		state = `NORMAL;
	end 
end

endcase

if(rdy) // If fpga uart is ready to send
begin
	// PC communication
	if(valid) // if fpga received valid data on uart receiver
	begin
		case (data_rx) // if fpga received data matches to...
			"t": begin
				LED1 <= ~LED1; // Toggle LED1
			end
			17: begin // Reset
				A4 <= 0;
			end
		endcase
		//data_tx <= data_rx; // fpga uart echo back received data
		//en <= 1; // enable fgpa transmitter uart
	end
end



end
endmodule
