#!/usr/bin/env python3


import math
import random

from gym import spaces
import numpy as np
from sentinal_walker.include.sentinal_walker.dependencies.walker_constants import INIT_POSES






class Sentinal_Turning_Signal:
    """
    Turning left or right wrt yaw Class for Sentinal robot Dog

    """
    def __init__(self) -> None:
        self.goal_reached = False
        self.stand_init_pose = INIT_POSES['stand']
        
        pass

    def stand_signal(self, t, action):
            if t > 0.1:
                return self.stand_init_pose
            t += 1
            # apply a 'brake' function
            signal = self.stand_init_pose * ((.1 + action[0]) / t + 1.5)
            return signal