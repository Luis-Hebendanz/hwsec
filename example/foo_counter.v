`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    11:31:02 03/06/2023 
// Design Name: 
// Module Name:    foo_counter 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module foo_counter(
    
	input wire clk,
	input wire rst,
	input wire en,
	output reg [7:0] cnt);
	
	// Wait for a rising clock edge
	always @(posedge clk)
	begin
	// Synchronous reset
	if(rst)
	begin
	cnt <= 8'd0; // Reset the cnt to 0
	end
	
	else // if(rst)
	begin
	// TODO: implement an enable
	cnt <= cnt + 1; // Count up
	end
	end

endmodule
