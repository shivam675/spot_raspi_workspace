#!/usr/bin/env python3


import math
import random

from gym import spaces
import numpy as np
from sentinal_walker.include.sentinal_walker.dependencies.walker_constants import INIT_POSES


STEP_PERIOD = 1.0 / 10.0  # 10 steps per second.


class Sentinal_Turning_Signal:
    """
    Turning left or right wrt yaw Class for Sentinal robot Dog

    """
    def __init__(self) -> None:
        self.goal_reached = False
        self.forward_init_pose = INIT_POSES['stand_ol']
        self.end_time = None
        self._init_orient = None
        self._init_orient
        
        pass

    ###### Helping functions #####
    def solve_direction(self):
        """
        Check if clockwise or not
        """
        diff = abs(self._init_orient - self._target_orient)
        clockwise = False
        if self._init_orient < self._target_orient:
            if diff > 3.14:
                clockwise = True
        else:
            if diff < 3.14:
                clockwise = True
        return clockwise

    #############################################

    def turning_signal(self, t, action):
        """
        turningSignal
        Action Space should be 2
        :params:
        t: current_time in seconds.
        action: 2 dimentional np array.

        :return:
        signal: numpy_array of dimention 12 
        """
        if self.goal_reached:
            self._stay_still = True
        initial_pose = INIT_POSES['stand_ol']
        period = STEP_PERIOD
        extension = 0.1
        swing = 0.03 + action[0]
        swipe = 0.05 + action[1]
        ith_leg = int(t / period) % 2
        pose = {
            'left_0': np.array([swipe, extension, -swing,
                                -swipe, extension, swing,
                                swipe, -extension, swing,
                                -swipe, -extension, -swing]),
            'left_1': np.array([-swipe, 0, swing,
                                swipe, 0, -swing,
                                -swipe, 0, -swing,
                                swipe, 0, swing]),
            'right_0': np.array([swipe, extension, swing,
                                 -swipe, extension, -swing,
                                 swipe, -extension, -swing,
                                 -swipe, -extension, swing]),
            'right_1': np.array([-swipe, 0, -swing,
                                 swipe, 0, swing,
                                 -swipe, 0, swing,
                                 swipe, 0, -swing])
        }
        clockwise = self.solve_direction()
        if clockwise:
            # turn right
            first_leg = pose['right_0']
            second_leg = pose['right_1']
        else:
            # turn left
            first_leg = pose['left_0']
            second_leg = pose['left_1']
        if ith_leg:
            signal = initial_pose + second_leg
        else:
            signal = initial_pose + first_leg
        return signal

