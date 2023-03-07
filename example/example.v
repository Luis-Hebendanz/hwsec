`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:53:11 03/06/2023 
// Design Name: 
// Module Name:    foo_and 
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
module foo_and(
    input wire A,
    input wire B,
    output reg Y
    );

always @ ( A or B )
begin
	assign Y = A & B;
end

endmodule
