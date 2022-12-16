#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>
#include <sensor_msgs/JointState.h>
#include <Adafruit_PWMServoDriver.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

ros::NodeHandle  nh;


void servo_cb(const sensor_msgs::JointState& cmd_msg){

    pwm.setPWM(0, 0, pulseWidth(cmd_msg.position[0]));
    pwm.setPWM(1, 0, pulseWidth(cmd_msg.position[1]));
    pwm.setPWM(2, 0, pulseWidth(cmd_msg.position[2]));
    
    pwm.setPWM(3, 0, pulseWidth(cmd_msg.position[3]));
    pwm.setPWM(4, 0, pulseWidth(cmd_msg.position[4]));
    pwm.setPWM(5, 0, pulseWidth(cmd_msg.position[5]));
    
    pwm.setPWM(6, 0, pulseWidth(cmd_msg.position[6]));
    pwm.setPWM(7, 0, pulseWidth(cmd_msg.position[7]));
    pwm.setPWM(8, 0, pulseWidth(cmd_msg.position[8]));

    pwm.setPWM(9, 0, pulseWidth(cmd_msg.position[9]));
    pwm.setPWM(10, 0, pulseWidth(cmd_msg.position[10]));
    pwm.setPWM(11, 0, pulseWidth(cmd_msg.position[11]));

    // if(cmd_msg.position[0] == 1){

    // }
    digitalWrite(13, HIGH-digitalRead(13));  
    // for(int i=0; i < 16; i++){
    //     Serial.println(cmd_msg.position[i]);
    // }


}


ros::Subscriber<sensor_msgs::JointState> sub("joint_states", servo_cb);

void setup(){
  // nh.getHardware()->setBaud(115200);
    // Serial.begin(115200);
    // Serial.println("16 channel Servo test!");
    delay(2);
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
  delay(10);
}