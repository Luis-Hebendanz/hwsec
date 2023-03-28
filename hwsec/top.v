`timescale 1ns / 1ps
`include "uart_defs.v"

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
	 output reg LED1,
	 output reg A4, // Reset
	 
	 // Gold
	 input wire A1, // TXD
	 output wire A0 // RXD
	 
    );
// Globals
reg rst = 0;

// ==== Gold Board =====
wire gold_valid;
wire [7:0] gold_data_rx;

uart_rx_sol gold_recv (
	.clk(CLK), 
	.rst(rst), 
	.din(A1), 
	.valid(gold_valid), // Set when received data is valid
	.data_out(gold_data_rx)
);

reg gold_en;
reg [7:0] gold_data_tx;
wire gold_rdy;
uart_tx_sol gold_tx (
	.clk(CLK),
	.rst(rst),
	.en(gold_en), // Enable bit (only set when rdy bit set)
	.data_in(gold_data_tx), // Data to transmit
	.rdy(gold_rdy), // Set when transmitter is ready to send again
	.dout(A0)
);

// ======== FPGA Uart ========
reg en = 0;
wire rdy;
reg [7:0] data_tx;
uart_tx_sol txi (
	.clk(CLK),
	.rst(rst),
	.en(en), // Enable bit (only set when rdy bit set)
	.data_in(data_tx), // Data to transmit
	.rdy(rdy), // Set when transmitter is ready to send again
	.dout(TX)
);
wire [7:0] data_rx;
wire valid;
uart_rx_sol rxi (
	.clk(CLK), 
	.rst(rst), 
	.din(RX), 
	.valid(valid), // Set when received data is valid
	.data_out(data_rx)
);


// Parameters
localparam SET_PWD = 3'b000,
				GET_PWD = 3'b001,
				ERROR = 3'b010,
				SEND_PWD = 3'b100,
				IDLE = 3'b111;

// Control flow vars		
reg [2:0] state = IDLE;
reg wait_flag = 0;

// Buffers
reg [7:0] gold_buf [0:15];
reg [7:0] fpga_buf [3:0];


// Counters
reg [7:0] gold_cnt_get = 8'b0;
reg [7:0] gold_cnt_set = 8'b0;
reg [31:0] clk_cnt = 0;
reg [7:0] fpga_cnt = 8'b0;


// Init Buffers
integer i;
initial begin
	for (i=0; i < 16; i=i+1) begin
		gold_buf[i] <= "A"+i;
	end 
end

// Main
always @(posedge CLK)
begin

en 			  	<= 0; // disable fpga transmitter
A4			 		<= 1; // reset is high so no reset
gold_en 			<= 0; // disable gold transmitter
LED1 				<= 0; // Disable LED
gold_cnt_get 	<= gold_cnt_get;
gold_cnt_set   <= gold_cnt_set;
state 			<= state;
data_tx 			<= data_tx;
gold_data_tx   <= gold_data_tx;

rst 				<= rst;

case(state)

SET_PWD: begin
	if(valid)
	begin
		gold_buf[gold_cnt_set]  <= data_rx;
		gold_cnt_set 				<= gold_cnt_set + 1;
	end

	if(gold_cnt_set >= 16)
	begin
		state <= IDLE;
	end
end

SEND_PWD: begin
	if(gold_rdy == 0) 
	begin
		wait_flag <= 0;
	end

	if(gold_rdy && wait_flag == 0) // if gold transmitter ready
	begin
		gold_data_tx 	<= gold_buf[gold_cnt_get];
		gold_cnt_get 	<= gold_cnt_get + 1;
		wait_flag 		<= 1;
		gold_en 			<= 1;
	end
	
	
	if(gold_cnt_get >= 16)
	begin
		state <= IDLE;
	end
end

GET_PWD: begin
	if(rdy == 0)
	begin
		wait_flag <= 0;
	end

	if(rdy && wait_flag == 0) // if fpga transmitter ready
	begin
		data_tx 			<= gold_buf[gold_cnt_get];
		gold_cnt_get 	<= gold_cnt_get + 1;
		wait_flag 		<= 1;
		en 				<= 1;
	end
	
	if(gold_cnt_get >= 16)
	begin
		state <= IDLE;
	end
end

ERROR: begin
	clk_cnt <= clk_cnt + 1; // number of clock cycles
	if(clk_cnt >= `UART_FULL_ETU)
	begin
		clk_cnt <= 0;
		LED1 <= ~LED1;
	end
end

IDLE: begin
	LED1 <= 1;
	
	if(gold_valid) // if fpga received data from gold board
	begin
		fpga_buf[fpga_cnt] <= gold_data_rx; // buffer gold data to fpga_buf[cnt]
		fpga_cnt <= fpga_cnt +1;
		
		if(fpga_cnt > 4) // check for buffer overflow
		begin
			state <= ERROR;
		end
	end
	
	if(rdy) // Check if fpga transmitter ready
	begin
		if(fpga_cnt > 0) // check if data is in fpga buffer 
		begin
			data_tx <= fpga_buf[fpga_cnt -1]; // send data from buffer at cnt - 1
			fpga_cnt <= fpga_cnt -1; // decrement cnt
			en <= 1;
		end
	end
	
	// PC communication
	if(valid) // if fpga received valid data on uart receiver
	begin
		case (data_rx) // if fpga received data matches to...
			"s": begin
				gold_cnt_set <= 0;
				state <= SET_PWD;
			end
			"p": begin
				gold_cnt_get <= 0;
				wait_flag <= 0;
				state <= SEND_PWD;
			end
			"g": begin
				gold_cnt_get <= 0;
				wait_flag <= 0;
				state <= GET_PWD;
			end
			27: begin // ESC Reset
				A4 <= 0;
			end
			default: begin
				if(rdy)
				begin
					data_tx <= data_rx;
					en <= 1;
				end else 
				begin
					state <= ERROR;
				end
			end
		endcase
	end
end

endcase




end
endmodule
