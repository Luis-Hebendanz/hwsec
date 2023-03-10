#!/usr/bin/env python3

import serial
import time
import sys
import re
import pdb


# Open the serial port
ser = serial.Serial('/dev/ttyUSB1', baudrate=115200)

f = open("log.txt", "w")

def get_pins():
    pins = []
    for i in range(6000, 10**4-2000):
        pin = f'{i:04d}'  # Format the number as a 4-digit string with leading zeros
        pin = pin.encode("ascii")
        pins.append(pin)
    return reversed(pins)


def pwd_failed(pin):
    m = b"\x00\r\nPIN is incorrect."
    tty_resp = ser.read(len(m))
    f.write(f"[{pin}]: {tty_resp}\n")
    print(f"Response: {tty_resp}")

    if m == tty_resp:
        sys.stderr.write("\n")
        return True
    return False

def reset():
    print("Resetting board.")
    ser.write("r".encode("ascii"))

    m = b"\r\n\x00Please enter the PIN:"
    tty_resp = ser.read(len(m))

    if m == tty_resp:
        sys.stderr.write("\n")
        return True
    print(f"res: {tty_resp}")


ser.write("r".encode())
m = b"Please enter the PIN:"
tty_resp = ser.read(len(m))

# Loop through the words and send them to the serial port
for word in get_pins():
    num = 0
    for b in word:
        num += ser.write(chr(b).encode("ascii"))
    print(f"num bytes: {num} -> {word}")

    if pwd_failed(word):
        reset()
    else:
        print("============== FOUND PASSWORD ==========")
        print(f"Password: {word}")
        sys.exit(0)



# Close the serial port
ser.close()


