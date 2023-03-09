#!/usr/bin/env python3

import serial
import time
import sys

# Open the serial port
ser = serial.Serial('/dev/ttyUSB1', baudrate=115200)
ser.timeout = 0.1

def reset():
    print("Resetting board.")
    ser.write(chr(17).encode("ascii"))

reset()

# Loop through the words and send them to the serial port
for a in range(33, 127):
    for b in range(33, 127):
        for c in range(33, 127):

            r = ser.read_until()
            print(r)
            word = chr(a) + chr(b) + chr(c) + '\n'
            word = word.encode("ascii")
            ser.write(word)
            print(f'Sent: {word}')
            time.sleep(0.07)

            res = ser.read_until()
            print(f"Response: {res}")
            if res == b'\r\n':
                reset()
            else:
                print("============== FOUND PASSWORD ==========")
                print(f"Password: {word}")
                sys.exit(0)



# Close the serial port
ser.close()


