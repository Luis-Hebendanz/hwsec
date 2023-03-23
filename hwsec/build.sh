#!/usr/bin/env bash

echo "==== FLASHING ======"
./papilio_pro/uart_blinky.py --build --program

echo "==== CONNECTION ===="
picocom -b 115200 /dev/ttyUSB1
