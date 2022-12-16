#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif
#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();





void sub_one_call_back( const std_msgs::UInt16& cmd_msg){

  pwm.setPWM(0, 0, pulseWidth(cmd_msg.data));
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}
ros::Subscriber<std_msgs::UInt16> sub_one_object("sub_one", sub_one_call_back);

#define MIN_PULSE_WIDTH 650
#define MAX_PULSE_WIDTH 2350
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50

void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub_one_object);

  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

}

int pulseWidth(int angle)
{
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




