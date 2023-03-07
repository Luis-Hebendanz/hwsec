#!/usr/bin/env bash

echo "==== FLASHING ======"
sudo xc3sprog -c papilio top.bit

echo "==== CONNECTION ===="
minicom -D /dev/ttyUSB1 -b 9600
