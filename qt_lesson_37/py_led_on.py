#!/usr/bin/env python3

import time
import serial

port = serial.Serial("/dev/ttyUSB0", 9600)


def onLed():
    port.write(b'1')


# time.sleep(1)
# port.write(b'0')
# time.sleep(1)

# while True:
#     port.write(b'1')
#     time.sleep(1)
#     port.write(b'0')
#     time.sleep(1)

time.sleep(2)
port.write(b'1')
# onLed()