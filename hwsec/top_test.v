`timescale 1ns / 1ps
`include "uart_defs.v"


module top_test;

	// Inputs
	reg CLK;
	
	// Outputs
	wire TX;
	wire LED1;
	wire A4;
	wire RX;

	// Instantiate the Unit Under Test (UUT)
	top uut (
		.CLK(CLK), 
		.RX(RX), 
		.TX(TX), 
		.LED1(LED1), 
		.A4(A4)
	);


	// Receiver from top
	// Outputs
	wire valid;
	wire [7:0] data_rx;
	
	uart_rx_sol rxi (
		.clk(CLK), 
		.rst(rst), 
		.din(TX), 
		.valid(valid), 
		.data_out(data_rx)
	);


	// Transmitter to top
	reg en;
	reg rst;
	wire rdy;
	reg [7:0] data_tx;
	uart_tx_sol txi (
		.clk(CLK),
		.rst(rst),
		.en(en), // Enable bit (only set when rdy bit set)
		.data_in(data_tx), // Data to transmit
		.rdy(rdy), // Set when transmitter is ready to send again
		.dout(RX)
	);

   parameter CLKS_TW = 10416 * 10;
	parameter END_TIME = CLKS_TW * 10;
	
	reg [31:0] clk_count = 0;
	always
	begin
		clk_count <= clk_count +1;
		#1 CLK <= ~CLK;
	end
	initial begin
		// Initialize Inputs
		CLK = 0;
		en = 0;
		rst = 0;
		data_tx = 8'b0;

		// Wait 100 ns for global reset to finish
		#`UART_FULL_ETU;
		if(rdy == 0)
		begin
			$display("Transmitter is not ready");
		end
		
      data_tx = "g";
		en = 1;
		
		// Add stimulus here
		#6118;
		en = 0;
	end
      
endmodule

