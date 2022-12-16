#!/usr/bin/env python3
import rospy
from sensor_msgs.msg import JointState



def main():
    msg = JointState()
    msg.position = [1,2,3,4,5,6,7,8,9,10,11,12]
    print(msg)
    pub.publish(msg)
    rate.sleep()



if __name__ == '__main__':
    rospy.init_node('joint_states_node', anonymous=True)
    pub = rospy.Publisher('joint_states', JointState, queue_size=5)
    rate = rospy.Rate(0.2)
    while not rospy.is_shutdown():
        main()