#!/usr/bin/env python3
import rospy
from std_msgs.msg import UInt16
import random
# import rosparam

def main():
    msg = UInt16()
    msg.data = random.randint(0,180)
    for i in list_of_pubs:
        print(msg.data)
        i.publish(msg)
    rate_1.sleep()



if __name__ == '__main__':
    rospy.init_node('string_driver_node', anonymous=True)
    rospy.sleep(1)
    rate_1 = rospy.Rate(0.5)
    # rate_2 = rospy.Rate(50)
    pub_1 = rospy.Publisher('flls', UInt16, queue_size=5)
    pub_2 = rospy.Publisher('flle', UInt16, queue_size=5)
    pub_3 = rospy.Publisher('fllw', UInt16, queue_size=5)
    pub_4 = rospy.Publisher('frls', UInt16, queue_size=5)
    pub_5 = rospy.Publisher('frle', UInt16, queue_size=5)
    pub_6 = rospy.Publisher('frlw', UInt16, queue_size=5)
    pub_7 = rospy.Publisher('rlls', UInt16, queue_size=5)
    pub_8 = rospy.Publisher('rlle', UInt16, queue_size=5)
    pub_9 = rospy.Publisher('rllw', UInt16, queue_size=5)
    pub_10 = rospy.Publisher('rrls', UInt16, queue_size=5)
    pub_11 = rospy.Publisher('rrle', UInt16, queue_size=5)
    pub_12 = rospy.Publisher('rrlw', UInt16, queue_size=5)
    list_of_pubs = [pub_1,pub_2,pub_3,pub_4,pub_5,pub_6,pub_7,pub_8,pub_9,pub_10,pub_11,pub_12,]
    while not rospy.is_shutdown():
        main()