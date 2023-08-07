#!/usr/bin/env python3

import serial
import time

try:
    port = serial.Serial("/dev/ttyUSB0", 9600)
except:
    print("Error")

# time.sleep(2)
port.write(b'0')