#!/usr/bin/env python3


import math
import random

from gym import spaces
import numpy as np
from sentinal_walker.include.sentinal_walker.dependencies.walker_constants import INIT_POSES


NUM_LEGS = 4
NUM_MOTORS = 3 * NUM_LEGS

class GallopLoopSignal:
    """
    Turning left or right wrt yaw Class for Sentinal robot Dog

    """
    def __init__(self) -> None:
        self.goal_reached = False
        self.forward_init_pose = INIT_POSES['stand_ol']
        self.end_time = None
        self._init_orient = None
        self._init_orient


    def gallop_signal(self, t, leg_pose):
        if self.goal_reached:
            coeff = self.evaluate_brakes_stage_coeff(t, [.0], end_t=self.end_time, end_value=0.0)
            leg_pose *= coeff
            if coeff is 0.0:
                self._stay_still = True
        motor_pose = np.zeros(NUM_MOTORS)
        for i in range(NUM_LEGS):
            motor_pose[int(3 * i)] = self.init_pose[3 * i]
            init_leg = self.init_pose[3 * i + 1]
            init_foot = self.init_pose[3 * i + 2]
            if i == 0 or i == 1:
                motor_pose[int(3 * i + 1)] = init_leg + leg_pose[0]
                motor_pose[int(3 * i + 2)] = init_foot + leg_pose[1]
            else:
                motor_pose[int(3 * i + 1)] = init_leg + leg_pose[2]
                motor_pose[int(3 * i + 2)] = init_foot + leg_pose[3]
        return motor_pose
    
    @staticmethod
    def evaluate_brakes_stage_coeff(current_t, action, end_t=0.0, end_value=0.0):
        # ramp function
        p = 1. + action[0]
        if end_t <= current_t <= p + end_t:
            return 1 - (current_t - end_t)
        else:
            return end_value