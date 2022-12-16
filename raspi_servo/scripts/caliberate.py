#!/usr/bin/env python3
from time import sleep
from adafruit_servokit import ServoKit
import rospy
import random
from itertools import cycle


# Set channels to the number of servo channels on your kit.
# 8 for FeatherWing, 16 for Shield/HAT/Bonnet.
kit = ServoKit(channels=16)
# k = cycle([0,180])

# for i in range(100):
#     # m = random.randint(4, 178)
#     m = next(k)
#     kit.servo[0].angle = m
#     kit.servo[2].angle = m
#     kit.servo[4].angle = m
#     kit.servo[6].angle = m
#     kit.servo[8].angle = m
#     kit.servo[10].angle = m
#     # kit.servo[1].angle = m
#     # kit.servo[1].angle = m
#     # kit.servo[1].angle = m
#     sleep(1)
#     # sleep(1)
m = 0

kit.servo[0].angle = m
kit.servo[2].angle = m
kit.servo[4].angle = m
kit.servo[6].angle = m
kit.servo[8].angle = m
kit.servo[10].angle = m

sleep(1)