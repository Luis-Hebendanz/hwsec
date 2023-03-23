#!/usr/bin/env python3

import sys
sys.path.append("./")

import subprocess

from pprint import pprint
from rhea.build.boards import get_board
from myhdl import (Signal, ResetSignal, intbv, always_seq, always,
                   always_comb)
from rhea import Global, Clock, Reset
import myhdl
import argparse



led_port_pin_map = {
    'ppro':  dict(name='led', pins=(112,)),
}


@myhdl.block
def ppro_blinky(led, clock, reset=None):
    """ a simple LED blinks example.
    This is intended to be used with the Xula, Stickit motherboard
    and an LED  pmod board.
    """
    maxcnt = int(clock.frequency)
    cnt = Signal(intbv(0, min=0, max=maxcnt))
    toggle = Signal(bool(0))

    @always_seq(clock.posedge, reset=None)
    def beh():
        if cnt == maxcnt-1:
            toggle.next = not toggle
            led.next = toggle
            cnt.next = 0
        else:
            cnt.next = cnt + 1

    return beh

def program(args):
    subprocess.check_call(args=["papilio", "./xilinx/pprov.bit"], executable="/usr/bin/xc3sprog", shell=True, env={})


def build(args):
    brd = get_board("ppro")
    # the design port names don't match the board pin names,
    # add the ports here (all the IO are a generic "chan")
    brd.add_port(**led_port_pin_map["ppro"])
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
