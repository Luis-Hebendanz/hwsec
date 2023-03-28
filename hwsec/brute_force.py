#!/usr/bin/env python3

import serial
import time
import sys
import re
import pdb
import string
import os
import itertools
from enum import Enum

# Open the serial port
ser = serial.Serial('/dev/ttyUSB1', baudrate=115200)

class Command(Enum):
    SET_PWD = 's'
    GET_PWD = 'g'
    SEND_PWD = 'p'
    RESET = chr(27)


def pwd_failed() -> bool:
    m = b"Password Incorrect.\r\n\x00"
    tty_resp = ser.read(len(m))
    #print(f"Response: {tty_resp}")

    if m == tty_resp:
        return True
    return False

def send_reset():
    #print("Resetting board.")
    ser.write(chr(27).encode("ascii"))

def reset():
    send_reset()

    m = b"Please enter the Password:\r\n\x00"
    tty_resp = ser.read(len(m))

    if m != tty_resp:
        raise Exception(f"Failed to reset board, res: '{tty_resp}'")



def send_command(cmd: Command, pwd: str = None):
    s = cmd.value.encode("ascii")
    #print(f"Sending {s}")
    num = ser.write(s)
    if num != 1:
        raise Exception("Failed sending full password")

    if cmd == Command.SEND_PWD and pwd != None:
        raise Exception("Send pwd should not have a password as argument")

    if pwd and cmd == Command.SET_PWD:
        s = pwd.encode("ascii")
        #print(f"Sending {s}")
        num = ser.write(s)
        if num != 16:
            raise Exception("Failed sending full password")

    if cmd == Command.GET_PWD:
        res = ser.read(16)
        return res.decode("ascii")

    return None

def generate_strings(length=16):
    chars = string.printable
    for item in itertools.product(chars, repeat=length):
        yield "".join(item)

def generate_incr_strings(length=16):
    from string import  digits, ascii_letters, punctuation
    chars = digits + ascii_letters + punctuation
    pwd = [chars[0] for i in range(length)]
    for i in range(length):
        for c in chars:
            pwd[i] = c
            yield "".join(pwd)

# Main
reset()
pwd_temp = send_command(Command.GET_PWD)
if pwd_temp != "ABCDEFGHIJKLMNOP":
    print(f"Password is not default. Is '{pwd_temp}'")


for pwd in generate_incr_strings():
    print(f"Cracking password: {pwd}")
    send_command(Command.SET_PWD, pwd)
    #pwd_temp = send_command(Command.GET_PWD)
    #if pwd != pwd_temp:
    #    raise Exception(f"Failed setting password got: '{pwd_temp}' expected: '{pwd}'")

    send_command(Command.SEND_PWD)
    if pwd_failed():
        reset()
        os.system('clear')
    else:
        print(f"====== Password is '{pwd}' ==========")
        break

# Close the serial port
ser.close()


