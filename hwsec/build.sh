#!/usr/bin/env bash

echo "==== FLASHING ======"
python -c 'import subprocess; subprocess.check_call(args=["papilio", "top.bit"], executable="/usr/bin/xc3sprog", shell=True, env={})'

echo "==== CONNECTION ===="
picocom -b 115200 /dev/ttyUSB1
