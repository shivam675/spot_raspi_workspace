#!/usr/bin/env python3
from time import sleep
from adafruit_servokit import ServoKit
import rospy
from std_msgs.msg import Int32MultiArray
# from numba import jit

kit = ServoKit(channels=16)

def execute_commands(msg):
    print(msg.data)
    if len(msg.data) != 12 or max(msg.data) > 180:
        print('Data size must have len 12 or one of the angle is greater than 180 deg')
 
    for idx, val in enumerate(msg.data):
        # if idx == 0:
        #     kit.servo[idx].angle = 180 - val
        # else:    
        kit.servo[idx].angle = val


if __name__ == '__main__':
    rospy.init_node('spot_ros_hardware_node', anonymous=True)
    rospy.sleep(1)
    rate = rospy.Rate(30)
    s = rospy.Subscriber('/hardware_actuator_node', Int32MultiArray, callback=execute_commands, queue_size=2)

    # while not rospy.is_shutdown():
    rospy.spin()
    rate.sleep()