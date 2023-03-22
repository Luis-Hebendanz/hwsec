#!/usr/bin/env bash

echo "==== FLASHING ======"
sudo xc3sprog -c papilio top.bit

echo "==== CONNECTION ===="
picocom -b 115200 /dev/ttyUSB1
