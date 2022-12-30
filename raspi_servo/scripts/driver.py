#!/usr/bin/env python3
from time import sleep
from adafruit_servokit import ServoKit
import rospy
from std_msgs.msg import Int32MultiArray
# from numba import jit

kit = ServoKit(channels=16)

def execute_commands(msg):
    print(msg.data)
    if (len(msg.data) != 12) or (max(msg.data) > 180) or (min(msg.data) < 0):
        print('Data size must have len 12 and all angles must be in [0, 180]')
        exit(1)
    
    # Send data to i2c device
    for idx, val in enumerate(msg.data): kit.servo[idx].angle = val


if __name__ == '__main__':
    rospy.init_node('spot_ros_hardware_node', anonymous=True)
    rospy.sleep(1)
    # rate = rospy.Rate(10)
    rate = rospy.Rate(10)
    s = rospy.Subscriber('/hardware_actuator_node', Int32MultiArray, callback=execute_commands, queue_size=2)

    # while not rospy.is_shutdown():
    rospy.spin()
    rate.sleep()