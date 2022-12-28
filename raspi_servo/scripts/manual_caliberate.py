#!/usr/bin/env python3
from time import sleep
from adafruit_servokit import ServoKit
import rospy
import random
from itertools import cycle


# Set channels to the number of servo channels on your kit.
# 8 for FeatherWing, 16 for Shield/HAT/Bonnet.
kit = ServoKit(channels=16)

while True:
    idx = input('idx : ')
    val = input('val : ')
    kit.servo[int(idx)].angle = int(val)
    print('Motor Number {} set to {} Degrees'.format(idx, val))