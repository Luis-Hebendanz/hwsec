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
	 
	 // Gold
	 input wire A1, // TXD
	 output wire A0, // RXD
	 
	 // Silver
	 output wire B14, // RXD 
	 input wire B15 // TXD
	 
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

// ==== Silver Board =====
wire silver_valid;
wire [7:0] silver_data_rx;
uart_rx_sol silver_recv (
	.clk(CLK), 
	.rst(rst), 
	.din(B15), // B15 is an input transmitter
	.valid(silver_valid), // Set when received data is valid
	.data_out(silver_data_rx)
);

reg silver_en;
reg [7:0] silver_data_tx;
wire silver_rdy;
uart_tx_sol silver_tx (
	.clk(CLK),
	.rst(rst),
	.en(silver_en), // Enable bit (only set when rdy bit set)
	.data_in(silver_data_tx), // Data to transmit
	.rdy(silver_rdy), // Set when transmitter is ready to send again
	.dout(B14) // B14 is an output receiver
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
`define PRE_NORMAL 3'b110
`define BOTH_GREEN 3'b001
`define G_GOLD 3'b010
`define G_SILVER 3'b011
`define BOTH_RED 3'b111
`define NONE 3'b100
reg [2:0] state = `NONE;


always @(posedge CLK)
begin

en <= 0; // disable fpga transmitter
gold_en <= 0; // disable gold transmitter
silver_en <= 0; // disable silver transmitter

case(state)

`NORMAL: begin
// Gold communication
if(gold_valid) // if gold send valid data
begin
	if(rdy) // if fpga transmitter is ready to send 
	begin
		data_tx <= gold_data_rx; // send gold data to fpga uart
		en <= 1; // enable fgpa transmitter uart
	end

	if(silver_rdy)
	begin
		silver_data_tx <= gold_data_rx; // send gold received data to silver board
		silver_en <= 1;
	end
end

// Silver communication
if(silver_valid) // if silver send valid data to fpga
begin
	if(rdy) // if fpga transmitter is ready to send 
	begin
		data_tx <= silver_data_rx; // send silver data to fpga uart
		en <= 1; // enable fgpa transmitter uart
	end
	
	if(gold_rdy) // if gold uart is ready to send
	begin
		gold_data_tx <= silver_data_rx; // send silver received data to gold board
		gold_en <= 1;
	end
end
end // end case

`BOTH_GREEN: begin
	if(gold_rdy & silver_rdy) // if gold & silver uart are ready to send
	begin
		gold_data_tx <= "G";  // Send G to gold board
		silver_data_tx <= "G"; // Send G to silver board
		gold_en <= 1;
		silver_en <= 1;
	end
end

`PRE_NORMAL: begin
	if(gold_rdy)
	begin
		gold_data_tx <= "G";  // Send G to gold board
		gold_en <= 1;
		state = `NORMAL;
	end
end

`G_GOLD: begin
	if(gold_rdy)
	begin
		gold_data_tx <= "G";  // Send G to gold board
		gold_en <= 1;
		state = `NONE;
	end
end

`G_SILVER: begin
	if(silver_rdy)
	begin
		silver_data_tx <= "G";  // Send G to gold board
		silver_en <= 1;
		state = `NONE;
	end
end

`BOTH_RED: begin
	state = `NONE; // Do nothing
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
			"1": begin
				state = `G_GOLD;
			end
			"2": begin
				state = `G_SILVER;
			end
			"G": begin
				state = `BOTH_GREEN;
			end
			"R": begin
				state = `BOTH_RED;
			end
			"N": begin
				state = `PRE_NORMAL;
			end
		endcase
		data_tx <= data_rx; // fpga uart echo back received data
		en <= 1; // enable fgpa transmitter uart
	end
end



end
endmodule
