`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   16:20:49 03/06/2023
// Design Name:   uart_tx
// Module Name:   /home/morty/ex1/uart_tx_test.v
// Project Name:  ex1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: uart_tx
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module uart_tx_test;

	// Inputs
	reg clk;
	reg rst;
	reg en;
	reg [7:0] data_tx;

	// Outputs
	wire rdy;
	wire dout;
  
   parameter clks_tw = 10416;



	// Instantiate the Unit Under Test (UUT)
	uart_tx uut (
		.clk(clk), 
		.rst(rst), 
		.en(en), 
		.data_tx(data_tx), 
		.rdy(rdy), 
		.dout(dout)
	);

	always
	begin
		#20 clk <= ~clk;
	end

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		en = 0;
		data_tx = 0;
      
        
		// Add stimulus here
		data_tx <= 8'b10101010;
		en <= 1;
		
//		clk <= 10416;
		
		#100000;

	end
      
endmodule

