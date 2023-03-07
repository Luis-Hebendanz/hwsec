`include "uart_defs.v"

module uart_tx_sol(
        input wire clk,
        input wire rst,
        input wire [7:0] data_in,
        input wire en,
        output reg dout = 1'b1,
        output reg rdy = 1'b1);

reg [7:0] data = 8'h00;
reg [1:0] state = `UART_START;
reg [2:0] bit_cnt = 3'b000;
reg [14:0] etu_cnt = 9'b0; //for baudrate 9600

wire etu_full;
assign etu_full = (etu_cnt == `UART_FULL_ETU);

always @(posedge clk)
begin
	if (rst)
	begin
		state <= `UART_START;
		dout <= 1'b1;
		rdy <= 1'b1;
	end

	else
	begin
		// Default assignments
		etu_cnt <= (etu_cnt + 1);
		dout <= dout;
		rdy <= rdy;
		data <= data;
		state <= state;
		bit_cnt <= bit_cnt;

		case(state)

			// Idle, waiting for enable
			`UART_START:
			begin
				if(en == 1)
				begin
					// Start bit
					dout <= 1'b0;
					data <= data_in;
					state <= `UART_DATA;
					etu_cnt <= 9'd0;
					bit_cnt <= 3'd0;
					rdy <= 1'b0;
				end
			end

			// Data Bits
			`UART_DATA:
			if(etu_full)
			begin
				etu_cnt <= 9'd0;
				bit_cnt <= (bit_cnt + 1);

				dout <= data[0];
				data <= {data[0], data[7:1]};

				if(bit_cnt == 3'd7)
				begin
					state <= `UART_STOP;
				end
			end

			// Stop Bit(s)
			`UART_STOP:
			if(etu_full)
			begin
				etu_cnt <= 9'd0;
				dout <= 1'b1;
				state <= `UART_IDLE;
			end

			// Idle time before restarting
			`UART_IDLE:
			if(etu_full)
			begin
				rdy <= 1'b1;
				state <= `UART_START;
			end

			default:
				$display ("UART TX: Invalid state 0x%X", state);

		endcase
	end
end

endmodule
