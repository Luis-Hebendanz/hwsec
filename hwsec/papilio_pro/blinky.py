#!/usr/bin/env python3

import sys
sys.path.append("./")

import subprocess

from pprint import pprint
from rhea.build.boards import get_board
from myhdl import (Signal, ResetSignal, intbv, always_seq, always,
                   always_comb)
import myhdl
import argparse

## Added
from rhea.cores.uart import uartbase
from rhea.cores.memmap import command_bridge
from rhea.cores.misc import glbl_timer_ticks, syncro
from rhea import Global, Clock, Reset
from rhea.system import Barebone
from rhea.system import FIFOBus
from rhea.build.boards import get_board
from rhea.cores.fifo import fifo_fast


led_port_pin_map = {
    'ppro':  dict(name='led', pins=(112,)),
}


@myhdl.block
def ppro_blinky(led, clock, uart_tx, reset=None):
    """ a simple LED blinks example.
    This is intended to be used with the Xula, Stickit motherboard
    and an LED  pmod board.
    """
    maxcnt = int(clock.frequency)
    cnt = Signal(intbv(0, min=0, max=maxcnt))
    toggle = Signal(bool(0))

    @always_seq(clock.posedge, reset=None)
    def blink():
        if cnt == maxcnt-1:
            toggle.next = not toggle
            led.next = toggle
            cnt.next = 0
        else:
            cnt.next = cnt + 1


    glbl = Global(clock, reset)

    # create the interfaces to the UART
    fifobus = FIFOBus(width=8)
    baudce, baudce16 = [Signal(bool(0)) for _ in range(2)]
    tx = Signal(bool(1))
    synctx_inst = syncro(clock, tx, uart_tx)

    # generate a strobe for the desired baud rate
    baud_inst = uartbase.uartbaud(glbl, baudce, baudce16, baudrate=115200)
    fifo_tx_inst = fifo_fast(glbl, fifobus, size=1)
    tx_inst = uartbase.uarttx(glbl, fifobus, tx, baudce)


    # create the UART instance.
    # uart_inst = uartlite(
    #     glbl, fifobus, serial_in=uart_rx, serial_out=uart_tx,
    #     fifosize=4
    # )

    @always_seq(clock.posedge, reset=None)
    def transmit():
        fifobus.write_data.next = 'A'
        fifobus.write.next = True

    return blink, transmit, baud_inst, fifo_tx_inst, tx_inst, synctx_inst

def program(args):
    subprocess.check_call(args=["papilio", "./xilinx/pprov.bit"], executable="/usr/bin/xc3sprog", shell=True, env={})


def build(args):
    brd = get_board("ppro")
    # the design port names don't match the board pin names,
    # add the ports here (all the IO are a generic "chan")
    brd.add_port(**led_port_pin_map["ppro"])
    brd.add_port_name('uart_tx', 'tx')
    flow = brd.get_flow(ppro_blinky)
    flow.run()
    info = flow.get_utilization()
    pprint(info)
    program(args)

def test_instance():
    # check for basic syntax errors, use test_ice* to test
    # functionality
    ppro_blinky(
        clock=Clock(0, frequency=50e6),
        led=Signal(intbv(0)[8:]) )


def cliparse():
    parser = argparse.ArgumentParser()
    parser.add_argument("--build", default=False, action='store_true')
    parser.add_argument("--test", default=False, action='store_true')
    parser.add_argument("--program", default=False, action='store_true')
    args = parser.parse_args()
    return parser, args


def main():
    parser, args = cliparse()

    if args.build:
        build(args)

    if args.program:
        program(args)

    if args.test:
        test_instance()

    if not args.build and not args.program and not args.test:
        parser.print_help()

if __name__ == '__main__':
    main()
