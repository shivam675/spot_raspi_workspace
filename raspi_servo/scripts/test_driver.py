#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int32MultiArray
import random
from itertools import cycle
k = cycle([2,175])


def test_driver_code():
    msg = Int32MultiArray()
    # val = random.randint(1, 179)
    val = next(k)
    msg.data = [val, val, val, val, val, val, val ,val, val, val, val ,val]
    print(val)
    pub.publish(msg)




if __name__ == '__main__':
    rospy.init_node('testing_driver', anonymous = True)
    rate = rospy.Rate(1.5)
    rospy.sleep(1)

    pub = rospy.Publisher('/hardware_actuator_node', Int32MultiArray, queue_size=2)

    while not rospy.is_shutdown():
        test_driver_code()
        rate.sleep()