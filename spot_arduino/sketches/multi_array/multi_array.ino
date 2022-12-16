
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt8MultiArray.h>
// #include <sensor_msgs/JointState.h>
#include <Adafruit_PWMServoDriver.h>

ros::NodeHandle  nh;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50


void servo_cb( const std_msgs::UInt8MultiArray& cmd_msg){
    int servo_list[12] = {1,2,3,4,5,6,7,8,9,10,11,12};
	for(short i = 0; i<12; i++){
	    pwm.setPWM(servo_list[i], 0, pulseWidth(cmd_msg.data[i]));
    } 
    digitalWrite(13, HIGH-digitalRead(13));  
}

ros::Subscriber<std_msgs::UInt8MultiArray> sub("joint_state_arrays", servo_cb);

void setup(){
    nh.getHardware()->setBaud(115200);
    Serial.begin(115200);
    Serial.println("16 channel Servo test!");
    nh.initNode();
    nh.subscribe(sub);
    delay(2);
    pwm.begin();
    pwm.setPWMFreq(FREQUENCY);
    delay(2);
    pinMode(13, OUTPUT);

}


int pulseWidth(int angle){
    int pulse_wide, analog_value;
    pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
    analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
    Serial.println(analog_value);
    return analog_value;
}



void loop(){
  nh.spinOnce();
  delay(20);
}


