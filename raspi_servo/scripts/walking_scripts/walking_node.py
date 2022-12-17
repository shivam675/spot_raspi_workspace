#!/usr/bin/env python3



import rospy
from std_msgs.msg import Int32MultiArray
import random
import math
from open_loop_walking_helper import OpenLoopWalking
import numpy as np
# from 

def main(motor_vals: np.array):
    msg = Int32MultiArray()
    # msg.data = random.randint(0, 180)
    # print(motor_vals)
    motor_vals = motor_vals.tolist()
    # print(motor_vals)
    msg.data = [abs(90 - int(math.degrees(i))) for i in motor_vals[0]]
    print(msg.data)
    publiser.publish(msg)




if __name__ == "__main__":
    rospy.init_node('servo_pub', anonymous=True)
    walker_instance = OpenLoopWalking()
    rate = rospy.Rate(10)
    publiser = rospy.Publisher('/hardware_actuator_node', Int32MultiArray, queue_size=1)
    current_time = 0
    temp_actions = np.zeros(8)
    # counter = 0
    while not rospy.is_shutdown():

        start_time = rospy.Time.now().to_sec()
        actions = walker_instance.open_loop_signal(current_time, temp_actions)
        # print(actions)

        main(actions)
        rate.sleep()
        mid_time = rospy.Time.now().to_sec()
       
        current_time +=  - start_time + mid_time
 