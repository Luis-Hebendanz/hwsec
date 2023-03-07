`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    10:24:08 03/07/2023 
// Design Name: 
// Module Name:    uart_rx 
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
module uart_rx(
    input wire clk,
    input wire rst,
    input wire din,
    output reg valid,
    output reg [7:0] data_rx
    );



`define RECV 3'b001
`define WAIT 3'b010
`define IDLE 3'b000

reg [2:0] state = `IDLE;
reg [15:0] cnt;
reg [7:0] bit_cnt;

always @(posedge clk)
begin

		cnt <= cnt +1;		
		case (state)
			`IDLE: begin
				if(din == 0)
				begin
					cnt <= 0;
					bit_cnt <= 0;
					state <= `WAIT;
				end
			end
			`WAIT: begin
			
				if(cnt >= glob.CLKS_TW / 2)
				begin
					cnt <= 0;
					state <= `RECV;
				end
				else if(din == 1)
				begin
					state <= `IDLE;
				end
			end
			`RECV: begin
				if(cnt >= glob.CLKS_TW && bit_cnt < 8)
				begin
					cnt <= 0;
					data_rx[bit_cnt] = din;
					bit_cnt <= bit_cnt +1;
				end
				
				if(cnt >= glob.CLKS_TW && bit_cnt >= 8)
				begin
					valid <= din;
					state <= `IDLE;
				end
			end
		endcase
end
endmodule
