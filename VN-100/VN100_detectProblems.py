!/usr/bin/env python

"""
Simple function to determine if there are major movements with the IMU based on the yaw, pitch, and roll.
"""

import pandas as pd

def detectProblems():
    # Read the csv
    path = "VNYMR.csv"
    df = pd.read_csv(path)
    # Determine if there are any major changes in yaw, pitch, or roll
    list = ["Yaw", "Pitch", "Roll"]
    for item in list:
        stats = df[item].describe() # Get summary statistics
        mean = stats[1]
        std = stats[2]
        out_thres_max = mean + 1.5 * std # outlier threshold --- use this for now
        out_thres_min = mean - 1.5 * std
        for val in df[item]:
            # Profit
            if val > out_thres_max or val < out_thres_min:
                return True # returns true if there's a problem
    return False
