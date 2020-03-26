#!/usr/bin/env python

"""
Simple script to collect pairs of yaw, pitch, and roll values from the IMU, 
and if there were major movements.
"""

from vnpy import *

def main():
    # Setup sensor
    s = VnSensor()
    s.connect("COM5", 115200) # change the connection parameter appropriately
    file = "test.txt" # filename

    # Setup IMU for the first reading then press enter
    x = input("Prepare for first reading")
    ypr1 = [s.read_yaw_pitch_roll().x, s.read_yaw_pitch_roll().y, s.read_yaw_pitch_roll().z]

    # Setup IMU for the second reading then press enter
    y = input("Prepare for second reading")
    ypr2 = [s.read_yaw_pitch_roll().x, s.read_yaw_pitch_roll().y, s.read_yaw_pitch_roll().z]

    z = input("Enter 0 if there was major movement, otherwise enter 1: ")
    while (z not in ["0", "1"]):
        z = input("Enter 0 if there was major movement, otherwise enter 1: ")

    f = open(file, "a+")
    f.write(str(ypr1) + " " + str(ypr2) + " " + z + "\n")
    f.close()

if __name__ == "__main__":
    main()
