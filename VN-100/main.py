#!/usr/bin/env python

"""
Simple script to determine if there are major movements with the IMU 
based on the yaw, pitch, and roll.
"""

from vnpy import *
import pandas as pd

# Initialize values
count = 0
prevYaw = 0
prevPitch = 0
prevRoll = 0
yawAvg = 0
pitchAvg = 0
rollAvg = 0


def checkYPR():
    currYPR = s.read_yaw_pitch_roll()
    yaw = currYPR.x
    pitch = currYPR.y
    roll = currYPR.z
    
    # Update average values
    count += 1
    yawAvg = ((yawAvg * (count - 1)) + yaw) / count
    pitchAvg = ((pitchAvg * (count - 1)) + pitch) / count
    rollAvg = ((rollAvg * (count - 1)) + roll) / count

    # Base algorithm: extreme movement if any of YPR is larger than average
    # Next algorithm: Compare the previous and current YPR values to assess major movement
        # Problem:
				# Roll or pitch changes by 45 degrees or more
				# Yaw changes by 60 degrees or more
    # return yaw > 1.5 * yawAvg or pitch > 1.5 * pitchAvg or roll > 1.5 * rollAvg

    problem = abs(roll - prevRoll) >= 45 or abs(pitch - prevPitch) >= 45  or abs(yaw - prevYaw) >= 60

    # Update previous values
    prevYaw = yaw
    prevPitch = pitch
    prevRoll = roll

    return problem


def main():
    # Setup sensor
    s = VnSensor()
    s.connect("COM5", 115200) # change the connection parameter appropriately
    prevYaw = s.read_yaw_pitch_roll().x
    prevPitch = s.read_yaw_pitch_roll().y
    prevRoll = s.read_yaw_pitch_roll().z

    while(True):
        problem = checkYPR()
        if (problem):
            # Do something
            print("Problem")
        else:
            print("No problem")


if __name__ == "__main__":
    main()
