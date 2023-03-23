// File: pprov.v
// Generated by MyHDL 0.11
// Date: Thu Mar 23 11:58:36 2023


`timescale 1ns/10ps

module pprov (
    led,
    button,
    clock
);
// a simple LED blinks example.
// This is intended to be used with the Xula, Stickit motherboard
// and an LED / button pmod board.

output led;
reg led;
input button;
input clock;

reg [24:0] cnt;
reg toggle;



always @(posedge clock) begin: PPROV_BEH
    if (($signed({1'b0, cnt}) == (32000000 - 1))) begin
        toggle <= (!toggle);
        cnt <= 0;
    end
    else begin
        cnt <= (cnt + 1);
    end
end


always @(toggle, button) begin: PPROV_BEH_ASSIGN
    if ((!button)) begin
        led = 1'b1;
    end
    else begin
        led = toggle;
    end
end

endmodule
