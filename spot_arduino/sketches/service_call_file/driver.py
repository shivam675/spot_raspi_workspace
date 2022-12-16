#!/usr/bin/python3
import rospy
from std_msgs.msg import String
from rosserial_arduino.srv import Test
import time

def main():
    print('entering service proxy')
    while not rospy.is_shutdown():
        t0 = time.time()
        res = sub_result.call('This is my string')
        t1 = time.time()
        print('{}  :  Time delay : {}'.format(res, t1-t0))



if __name__ == '__main__':
    rospy.init_node('string_driver_node', anonymous=True)
    rospy.sleep(1)
    custom_srv = Test()
    sub_result = rospy.ServiceProxy('test_srv', custom_srv)
    main()