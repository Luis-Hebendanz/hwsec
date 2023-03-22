#!/usr/bin/env python3

import serial
import time
import sys
import re
import pdb
import string
import itertools


# Open the serial port
ser = serial.Serial('/dev/ttyUSB1', baudrate=115200)



def pwd_failed():
    m = b"\x00\r\nPIN is incorrect."
    tty_resp = ser.read(len(m))
    print(f"Response: {tty_resp}")

    if m == tty_resp:
        sys.stderr.write("\n")
        return True
    return False

def send_reset():
    print("Resetting board.")
    ser.write(chr(27).encode("ascii"))

def reset():
    send_reset()

    m = b"\r\n\x00Please enter the PIN:"
    tty_resp = ser.read(len(m))

    if m == tty_resp:
        sys.stderr.write("\n")
        return True
    print(f"res: {tty_resp}")


def generate_strings(length=16):
    chars = string.printable
    for item in itertools.product(chars, repeat=length):
        yield "".join(item)


# Main
send_reset()
for pwd in generate_strings():
    print(f"pwd: {pwd}")
    num = ser.write(pwd.encode("ascii"))
    if num != 16:
        print("Failed sending full password")
        sys.exit(-1)




# Close the serial port
ser.close()


