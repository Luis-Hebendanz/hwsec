`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:35:58 03/06/2023
// Design Name:   foo_counter
// Module Name:   /home/morty/example/ex2_tb.v
// Project Name:  ex1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: foo_counter
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ex2_tb;

	// Inputs
	reg clk;
	reg rst;
	reg en;

	// Outputs
	wire [7:0] cnt;

	// Instantiate the Unit Under Test (UUT)
	foo_counter uut (
		.clk(clk), 
		.rst(rst), 
		.en(en), 
		.cnt(cnt)
	);

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		en = 0;
   end
		// Generate a 50MHz clock
	always
	begin
	#10 clk <= ~clk;
	end
	// After 2 clock cycles reset for 2 clock cycles
	initial
	begin
	#40 rst <= 1'b1;
	#40 rst <= 1'b0;
	end
	// After 5 clock cycles enable for 5 clock cycles
	initial
	begin
	#100 en <= 1'b1;
	#100 en <= 1'b0;
	end
        
		// Add stimulus here


      
endmodule

