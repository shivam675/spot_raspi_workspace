#!/usr/bin/env python3


import math
import random
import numpy as np
from sentinal_walker.include.sentinal_walker.dependencies.walker_constants import INIT_POSES
from sentinal_walker.dependencies.kinematics import Kinematics





class MultiPoseSignal:
    """
    Turning left or right wrt yaw Class for Sentinal robot Dog

    """
    def __init__(self) -> None:
        self.goal_reached = False
        self.stand_init_pose = INIT_POSES['stand']


    def signal(self, t, action):
        # if not self.manual_control:
        #     stage_coeff = self._evaluate_stage_coefficient(t, action)
        #     staged_value = self.target_value * stage_coeff
        #     self.values[self.next_pose] = (self.values[self.next_pose][0],
        #                                    self.values[self.next_pose][1],
        #                                    staged_value)
        #     self.position = np.array([
        #         self.values["base_x"][2],
        #         self.values["base_y"][2],
        #         self.values["base_z"][2]
        #     ])
        #     self.orientation = np.array([
        #         self.values["roll"][2],
        #         self.values["pitch"][2],
        #         self.values["yaw"][2]
        #     ])
        # else:
        self.position, self.orientation = self.read_inputs_via_hardware()
        kinematics = Kinematics()
        fr_angles, fl_angles, rr_angles, rl_angles, _ = kinematics.solve(self.orientation, self.position)
        signal = [
            fl_angles[0], fl_angles[1], fl_angles[2],
            fr_angles[0], fr_angles[1], fr_angles[2],
            rl_angles[0], rl_angles[1], rl_angles[2],
            rr_angles[0], rr_angles[1], rr_angles[2]
        ]
        return signal


    def read_inputs_via_hardware(self):
        position = np.array(
            [
                self._pybullet_client.readUserDebugParameter(self.base_x),
                self._pybullet_client.readUserDebugParameter(self.base_y),
                self._pybullet_client.readUserDebugParameter(self.base_z)
            ]
        )
        orientation = np.array(
            [
                self._pybullet_client.readUserDebugParameter(self.roll),
                self._pybullet_client.readUserDebugParameter(self.pitch),
                self._pybullet_client.readUserDebugParameter(self.yaw)
            ]
        )
        return position, orientation

