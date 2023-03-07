`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:16:25 03/06/2023 
// Design Name: 
// Module Name:    uart_tx 
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


module uart_tx(
    input wire clk,
	 input wire rst,
    input wire en,
    input wire [7:0] data_tx,
    output reg rdy = 1,
    output reg dout = 1
    );

reg [15:0] cnt;
reg [7:0] bit_cnt;
reg [7:0] data_tx_reg;
parameter clks_tw = 10416;


`define SEND 3'b001
`define IDLE 3'b000
`define STOP 3'b010
reg [2:0] state = `IDLE;


always @(posedge clk)
begin

	if(en)
	begin
		cnt <= cnt +1;		
		case (state)
			`IDLE: begin
				data_tx_reg <= data_tx;
				rdy <= 0;
				bit_cnt <= 0;
				dout <= 0;
				cnt <= 0;
				state <= `SEND;
			end
			
			`SEND: begin
				if(cnt >= clks_tw && bit_cnt < 8)
				begin
					dout <= data_tx_reg[bit_cnt];
					bit_cnt <= bit_cnt +1;
					cnt <= 0;
				end
				
				if(cnt >= clks_tw && bit_cnt >= 8)
				begin
					dout <= 1;
					cnt <= 0;
					state = `STOP;
				end
			end
			
			`STOP: begin				
				if(cnt >= clks_tw)
				begin
					rdy <= 1;
					state = `IDLE;
				end
			end
		endcase
		

		
		

		
	end



end

endmodule
