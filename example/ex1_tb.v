`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:10:56 03/06/2023
// Design Name:   foo_and
// Module Name:   /home/morty/example/ex1_tb.v
// Project Name:  ex1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: foo_and
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ex1_tb;

	// Inputs
	reg A;
	reg B;

	// Outputs
	wire Y;

	// Instantiate the Unit Under Test (UUT)
	foo_and uut (
		.A(A), 
		.B(B), 
		.Y(Y)
	);

	initial begin
		// Initialize Inputs
		A = 0;
		B = 0;
      end
		
     // Toggle A every 50 nanoseconds
      always
      begin
         #50 A <= ~A;
		end
		
		// Toggle B every 100 nanoseconds
		always
		begin
		#100 B <= ~B;
		end



		
        
		// Add stimulus here

	
      
endmodule

