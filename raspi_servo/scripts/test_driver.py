#!/usr/bin/env python3

import rospy
from std_msgs.msg import Int8MultiArray


def test_driver_code():
    msg = Int8MultiArray()
    msg.data = [1,2,3,4,5,6,7,8,9,10,11,12]
    pub.publish(msg)




if __name__ == '__main__':
    rospy.init_node('testing_driver', anonymous = True)
    rate = rospy.Rate(30)
    rospy.sleep(1)

    pub = rospy.Publisher('/hardware_actuator_node', Int8MultiArray, queue_size=2)

    while not rospy.is_shutdown():
        test_driver_code()
        rate.sleep()