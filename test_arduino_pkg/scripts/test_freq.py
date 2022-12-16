#!/usr/bin/env python3



import rospy
from std_msgs.msg import UInt16
import random
import math
from start_walking import OpenLoopWalking
import numpy as np
# from 

def main(motor_vals):
    msg = UInt16()
    # msg.data = random.randint(0, 180)
    # print(motor_vals)
    msg.data = 90 - int(math.degrees(motor_vals[0][1]))
    print(msg.data)
    publiser.publish(msg)




if __name__ == "__main__":
    rospy.init_node('servo_pub', anonymous=True)
    walker_instance = OpenLoopWalking()
    rate = rospy.Rate(10)
    publiser = rospy.Publisher('/servo', UInt16, queue_size=1)
    current_time = 0
    temp_actions = np.zeros(8)
    counter = 0
    while not rospy.is_shutdown():

        start_time = rospy.Time.now().to_sec()
        actions = walker_instance.open_loop_signal(current_time, temp_actions)
        # print(actions)
        main(actions)
        rate.sleep()
        # print(current_time)
        mid_time = rospy.Time.now().to_sec()
        # rect = mid_time - start_time
        
        current_time +=  - start_time + mid_time
        # t2 = rospy.Time.now()
        # print((t2.to_sec() - t1.to_sec())*1000)
    