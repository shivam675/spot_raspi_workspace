#!/usr/bin/env python3
import rospy
from std_msgs.msg import UInt8MultiArray
import random



def main():
    msg = UInt8MultiArray()
    # msg.
    sv1 = random.randint(2, 179)
    msg.data = [sv1,2,3,4,5,6,7,8,9,10,11,12]

    pub.publish(msg)
    rate.sleep()



if __name__ == '__main__':
    rospy.init_node('joint_states_node', anonymous=True)
    pub = rospy.Publisher('joint_state_arrays', UInt8MultiArray, queue_size=5)
    rate = rospy.Rate(10)
    while not rospy.is_shutdown():
        main()