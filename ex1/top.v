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
`define ERROR 3'b100
`define NONE 3'b111

reg [2:0] state = `NORMAL;
reg [3:0][7:0] fpga_buf;
reg [7:0] fpga_cnt = 8'b0;

reg [3:0][7:0] gold_buf;
reg [7:0] gold_cnt = 8'b0;

initial begin
	gold_buf[0] = 8'h11;
	gold_buf[1] = 8'h22;
	gold_buf[2] = 8'h33;
	gold_buf[3] = 8'h44;
end

always @(posedge CLK)
begin

en <= 0; // disable fpga transmitter
gold_en <= 0; // disable gold transmitter
A4 <= 1;

case(state)

`NORMAL: begin
	if(gold_valid) // if fpga received data from gold board
	begin
		fpga_buf[fpga_cnt] <= gold_data_rx; // buffer gold data to fpga_buf[cnt]
		fpga_cnt <= fpga_cnt +1;
		
		if(fpga_cnt > 4) // check for buffer overflow
		begin
			state = `ERROR;
		end
	end
	
	if(rdy) // Check if fpga transmitter ready
	begin
		if(fpga_cnt > 0) // check if data is in fpga buffer 
		begin
			data_tx <= fpga_buf[fpga_cnt -1]; // send data from buffer at cnt - 1
			fpga_cnt <= fpga_cnt -1; // decrement cnt
			en <= 1;
		end
	end
	
	if(valid) // If data received from pc
	begin
		gold_buf[gold_cnt] <= data_rx; // save to gold_buf
		gold_cnt <= gold_cnt +1; // increment gold_cnt
		
		if(gold_cnt > 4) // check for buffer overflow
		begin
			state = `ERROR;
		end
	end
	
	if(gold_rdy) // if gold transmitter ready
	begin
		if(gold_cnt > 0) // If data in gold_buf
		begin
			gold_data_tx <= gold_buf[gold_cnt -1]; // send gold_buf[cnt] to gold board
			gold_cnt <= gold_cnt -1; // decrement gold_cnt
			gold_en <= 1; // enable gold transmitter
		end
	end
end

`ERROR: begin
	LED1 <= 1;
end

endcase


// PC communication
if(valid) // if fpga received valid data on uart receiver
begin
	case (data_rx) // if fpga received data matches to...
		"t": begin
			LED1 <= ~LED1; // Toggle LED1
		end
		"r": begin // Reset
			A4 <= 0;
		end
	endcase
end




end
endmodule
