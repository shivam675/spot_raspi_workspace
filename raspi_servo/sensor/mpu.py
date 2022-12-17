# SPDX-FileCopyrightText: 2021 ladyada for Adafruit Industries
# SPDX-License-Identifier: MIT
import rospy
import time
import board
import adafruit_mpu6050
from sensor_msgs.msg import Imu, Temperature
from math import atan2, sqrt, pi
from tf.transformations import quaternion_from_euler


RT = 60

def get_angels(ang_vel, lin_acc):

    ay = atan2(lin_acc[0], sqrt( pow(lin_acc[1], 2) + pow(lin_acc[2], 2))) * 180 / pi
    ax = atan2(lin_acc[1], sqrt( pow(lin_acc[0], 2) + pow(lin_acc[2], 2))) * 180 / pi

    gx = gx + ang_vel[0] / RT
    gy = gy - ang_vel[1] / RT
    gz = gz + ang_vel[2] / RT

    gx = gx * 0.96 + ax * 0.04
    gy = gy * 0.96 + ay * 0.04

    return quaternion_from_euler(gx, gy, 0)


def data_publisher():
    msg = Imu()
    temp_msg = Temperature()
    
    ang_vel = mpu.gyro
    lin_acc = mpu.acceleration

    msg.angular_velocity.x = ang_vel[0]
    msg.angular_velocity.y = ang_vel[1]
    msg.angular_velocity.z = ang_vel[2]

    msg.linear_acceleration.x = lin_acc[0]
    msg.linear_acceleration.y = lin_acc[1]
    msg.linear_acceleration.z = lin_acc[2]

    xyzw = get_angels(ang_vel, lin_acc)
    msg.orientation.x = xyzw[0]
    msg.orientation.y = xyzw[1]
    msg.orientation.z = xyzw[2]
    msg.orientation.w = xyzw[3]

    temp_msg.temperature = mpu.temperature

    imu_object.publish(msg)
    temperature_object.publish(temp_msg)


    rate.sleep()





if __name__ == "__main__":
    rospy.init_node('mpu_node', anonymous=True)
    rospy.sleep(1)

    i2c = board.I2C()  # uses board.SCL and board.SDA
    mpu = adafruit_mpu6050.MPU6050(i2c)

    rate = rospy.Rate(RT)
    imu_object = rospy.Publisher('imu_data', Imu, queue_size=2)
    temperature_object = rospy.Publisher('temperature', Temperature, queue_size=2)


    initial_vel = 0
    start_time = rospy.Time.now()
    while not rospy.is_shutdown():
        data_publisher()
        