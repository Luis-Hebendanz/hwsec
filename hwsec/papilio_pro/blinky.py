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



led_port_pin_map = {
    'ppro':  dict(name='led', pins=(112,)),
}


@myhdl.block
def ppro_blinky(led, button, clock, reset=None):
    """ a simple LED blinks example.
    This is intended to be used with the Xula, Stickit motherboard
    and an LED / button pmod board.
    """
    maxcnt = int(clock.frequency)
    cnt = Signal(intbv(0, min=0, max=maxcnt))
    toggle = Signal(bool(0))

    @always_seq(clock.posedge, reset=None)
    def beh():
        if cnt == maxcnt-1:
            toggle.next = not toggle
            cnt.next = 0
        else:
            cnt.next = cnt + 1

    @always_comb
    def beh_assign():
        if not button:
            led.next = True
        else:
            led.next = toggle

    return beh, beh_assign


def program(args):
    subprocess.check_call(args=["papilio", "./xilinx/pprov.bit"], executable="/usr/bin/xc3sprog", shell=True, env={})


def build(args):
    brd = get_board(args.brd)
    # the design port names don't match the board pin names,
    # add the ports here (all the IO are a generic "chan")
    brd.add_port(**led_port_pin_map[args.brd])
    brd.add_port(name='button', pins=(114,))
    flow = brd.get_flow(ppro_blinky)
    flow.run()
    info = flow.get_utilization()
    pprint(info)
    program(args)

def cliparse():
    parser = argparse.ArgumentParser()
    parser.add_argument("--brd", default='ppro')
    parser.add_argument("--flow", default="ise")
    parser.add_argument("--build", default=False, action='store_true')
    parser.add_argument("--test", default=False, action='store_true')
    parser.add_argument("--program", default=False, action='store_true')
    args = parser.parse_args()
    return args


def main():
    args = cliparse()

    if args.build:
        build(args)

    if args.program:
        program(args)


if __name__ == '__main__':
    main()
