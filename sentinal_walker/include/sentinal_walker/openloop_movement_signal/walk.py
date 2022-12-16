#!/usr/bin/env python3


import math
import random

from gym import spaces
import numpy as np
from sentinal_walker.include.sentinal_walker.dependencies.walker_constants import INIT_POSES





class Sentinal_Walking_Signal:
    """
    Walking Class for Sentinal robot Dog

    """
    def __init__(self) -> None:
        self.goal_reached = False
        self.forward_init_pose = INIT_POSES['stand_ol']
        self.end_time = None
        
        pass

    ###### Static Methods Helping functions #####

    @staticmethod
    def evaluate_forward_brakes_stage_coefficient(current_t, action, end_t=0.0, end_value=0.0):
        # ramp function
        p = 0.8 + action[1]
        if end_t <= current_t <= p + end_t:
            return 1 - (current_t - end_t)
        else:
            return end_value

    @staticmethod
    def evaluate_forward_gait_stage_coefficient(current_t, action, end_t=0.0):
        # ramp function
        p = 0.8 + action[0]
        if end_t <= current_t <= p + end_t:
            return current_t
        else:
            return 1.0

    #############################################


    def forward_walk_signal(self, t: float, action: np.array):
        """
        Walking_Signal
        Action Space should be 8
        :params:
        t: current_time in seconds.
        action: 8 dimentional np array. 
        """

        period = 1.0 / 8
        l_a = 0.1
        f_a = l_a * 2
        if self.goal_reached:
            coeff = self.evaluate_forward_brakes_stage_coefficient(t, [0., 0.], end_t=self.end_time, end_value=0.0)
            l_a *= coeff
            f_a *= coeff
            if coeff == 0.0:
                self._stay_still = True
        start_coeff = self.evaluate_forward_gait_stage_coefficient(t, [0.0])
        l_a *= start_coeff
        f_a *= start_coeff
        l_extension = l_a * math.cos(2 * math.pi / period * t)
        f_extension = f_a * math.cos(2 * math.pi / period * t)
        initial_pose = self.forward_init_pose
        l_swing = -l_extension
        swing = -f_extension
        pose = np.array([0.0, l_extension + action[0], f_extension + action[1],
                         0.0, l_swing + action[2], swing + action[3],
                         0.0, l_swing + action[4], swing + action[5],
                         0.0, l_extension + action[6], f_extension + action[7]])

        signal = initial_pose + pose
        return signal


