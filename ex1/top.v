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
	 output reg LED1
    );

// Outputs
wire rdy;
wire valid;
wire [7:0] data_rx;

// Inputs
reg rst = 0;
reg en = 0;
reg [7:0] data_tx;


uart_tx_sol txi (
	.clk(CLK),
	.rst(rst),
	.en(en), // Enable bit (only set when rdy bit set)
	.data_in(data_tx), // Data to transmit
	.rdy(rdy), // Set when transmitter is ready to send again
	.dout(TX)
);

uart_rx_sol rxi (
	.clk(CLK), 
	.rst(rst), 
	.din(RX), 
	.valid(valid), // Set when received data is valid
	.data_out(data_rx)
);

always @(posedge CLK)
begin

en <= 0;


if(valid)
begin
	if(rdy == 1)
	begin
		data_tx <= data_rx;
		en <= 1;
		if(data_rx == "L")
		begin
			LED1 <= 1;
		end else
		begin
			LED1 <= 0;
		end
	end
end


end
endmodule
