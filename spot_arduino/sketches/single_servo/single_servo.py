#!/usr/bin/env python3
import rospy
from std_msgs.msg import UInt16
import random
# import rosparam

def main():
    # for i in range(5):
    msg = UInt16()
    msg.data = random.randint(0,180)
    print(msg.data)
    pub_1.publish(msg)
    rate_1.sleep()

# for j in range(50):
    pub_2.publish(msg)
    rate_1.sleep()
    # rate_2.sleep()


if __name__ == '__main__':
    rospy.init_node('string_driver_node', anonymous=True)
    rospy.sleep(1)
    rate_1 = rospy.Rate(3)
    # rate_2 = rospy.Rate(50)
    pub_1 = rospy.Publisher('sub_one', UInt16, queue_size=5)
    pub_2 = rospy.Publisher('sub_two', UInt16, queue_size=5)
    while not rospy.is_shutdown():
        main()