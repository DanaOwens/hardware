#!/usr/bin/env python

"""
Simple script to determine if there are major movements with the IMU 
based on the yaw, pitch, and roll.
"""

from vnpy import *
from joblib import load
import time


def checkYPR(s, prevYaw, prevPitch, prevRoll):
    # Algorithm: Compare the previous and current YPR values to assess major movement
        # Problem:
			# Roll or pitch changes by 45 degrees or more
		    # Yaw changes by 60 degrees or more
    currYPR = s.read_yaw_pitch_roll()

    model = load('yprClassifier.joblib')
    pred = model.predict([[prevYaw, prevPitch, prevRoll, currYPR.x, currYPR.y, currYPR.z]])
    modelProblem = pred == [[0]]

    problem = abs(currYPR.z - prevRoll) >= 45 or abs(currYPR.y - prevPitch) >= 45  or abs(currYPR.x - prevYaw) >= 60
    return modelProblem or problem


def main():
    # Setup sensor
    s = VnSensor()
    s.connect("COM5", 115200) # change the connection parameter appropriately

    while(True):
        currYPR = s.read_yaw_pitch_roll()
        yaw = currYPR.x
        pitch = currYPR.y
        roll = currYPR.z
        time.sleep(0.5) # Delay 0.5 seconds
        problem = checkYPR(s, yaw, pitch, roll)

        if (problem):
        # Do something
            print("Problem")
        else:
            print("No problem")


if __name__ == "__main__":
    main()