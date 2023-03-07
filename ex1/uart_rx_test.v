`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   10:59:40 03/07/2023
// Design Name:   uart_rx
// Module Name:   /home/morty/ex1/uart_rx_test.v
// Project Name:  ex1
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: uart_rx
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module uart_rx_test;

	// Inputs
	reg clk;
	reg rst;
	reg en;
	reg [7:0] data_tx;

	// Outputs
	wire valid;
	wire rdy;
	wire dout;
	wire [7:0] data_rx;

	// Constant
   parameter CLKS_TW = 10416 * 10;
	parameter END_TIME = CLKS_TW * 10;
	
	uart_tx txi (
		.clk(clk),
		.rst(rst),
		.en(en), 
		.data_tx(data_tx), 
		.rdy(rdy), 
		.dout(dout)
	);

	// Instantiate the Unit Under Test (UUT)
	uart_rx rxi (
		.clk(clk), 
		.rst(rst), 
		.din(dout), 
		.valid(valid), 
		.data_rx(data_rx)
	);


always
begin
	#10 clk <= ~clk;
end

	initial begin
		// Initialize Inputs
		clk = 0;
		rst = 0;
		en = 0;
		
		#CLKS_TW
		
		data_tx <= 8'b11110111;
		en = 1;

		#END_TIME
      
		if(valid == 1)
		begin 
			
		end
		
		// Add stimulus here
		
	end
      
endmodule

