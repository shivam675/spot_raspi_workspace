#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

// -------------------------------------------------------//
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>
// -------------------------------------------------------//
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
ros::NodeHandle  nh;

// -------------------------------------------------------//
// uint8_t flls = 0;
// uint8_t flle = 1;
// uint8_t fllw = 2;

// uint8_t frls = 3;
// uint8_t frle = 4;
// uint8_t frlw = 5;

// uint8_t rlls = 6;
// uint8_t rlle = 7;
// uint8_t rllw = 8;

// uint8_t rrls = 9;
// uint8_t rrle = 10;
// uint8_t rrlw = 11;

// -----------------------------------------------------//



void flls_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(0, 0, pulseWidth(cmd_msg.data));
}
void flle_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(1, 0, pulseWidth(cmd_msg.data));
}
void fllw_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(2, 0, pulseWidth(cmd_msg.data));
}



void frls_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(3, 0, pulseWidth(cmd_msg.data));
}
void frle_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(4, 0, pulseWidth(cmd_msg.data));
}
void frlw_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(5, 0, pulseWidth(cmd_msg.data));
}




void rlls_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(6, 0, pulseWidth(cmd_msg.data));
}
void rlle_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(7, 0, pulseWidth(cmd_msg.data));
}
void rllw_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(8, 0, pulseWidth(cmd_msg.data));
}



void rrls_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(9, 0, pulseWidth(cmd_msg.data));
}
void rrle_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(10, 0, pulseWidth(cmd_msg.data));
}
void rrlw_cb( const std_msgs::UInt16& cmd_msg) {
  pwm.setPWM(11, 0, pulseWidth(cmd_msg.data));
}
// -----------------------------------------------------//



ros::Subscriber<std_msgs::UInt16> flls_sub("flls", flls_cb);
ros::Subscriber<std_msgs::UInt16> flle_sub("flle", flle_cb);
ros::Subscriber<std_msgs::UInt16> fllw_sub("fllw", fllw_cb);

ros::Subscriber<std_msgs::UInt16> frls_sub("frls", frls_cb);
ros::Subscriber<std_msgs::UInt16> frle_sub("frle", frle_cb);
ros::Subscriber<std_msgs::UInt16> frlw_sub("frlw", frlw_cb);

ros::Subscriber<std_msgs::UInt16> rlls_sub("rlls", rlls_cb);
ros::Subscriber<std_msgs::UInt16> rlle_sub("rlle", rlle_cb);
ros::Subscriber<std_msgs::UInt16> rllw_sub("rllw", rllw_cb);

ros::Subscriber<std_msgs::UInt16> rrls_sub("rrls", rrls_cb);
ros::Subscriber<std_msgs::UInt16> rrle_sub("rrle", rrle_cb);
ros::Subscriber<std_msgs::UInt16> rrlw_sub("rrlw", rrlw_cb);

//------------------------------------------------------//

// -------------------------------------------------------//
#define MIN_PULSE_WIDTH 544
#define MAX_PULSE_WIDTH 2400
#define DEFAULT_PULSE_WIDTH 1500
#define FREQUENCY 50  

int enA = 9;
int in1 = 13;
int in2 = 12;

void setup() {
  nh.initNode();
  
  pwm.begin();
  pwm.setPWMFreq(FREQUENCY);

  pinMode(enA, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in1, OUTPUT);
  
  analogWrite(enA, 105);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  nh.subscribe(flls_sub);
  nh.subscribe(flle_sub);
  nh.subscribe(fllw_sub);

  nh.subscribe(frls_sub);
  nh.subscribe(frle_sub);
  nh.subscribe(frlw_sub);

  nh.subscribe(rlls_sub);
  nh.subscribe(rlle_sub);
  nh.subscribe(rllw_sub);

  nh.subscribe(rrls_sub);
  nh.subscribe(rrle_sub);
  nh.subscribe(rrlw_sub);

}

//-------------------------------------------------------//
int pulseWidth(int angle) {
  int pulse_wide, analog_value;
  pulse_wide = map(angle, 0, 180, MIN_PULSE_WIDTH, MAX_PULSE_WIDTH);
  analog_value = int(float(pulse_wide) / 1000000 * FREQUENCY * 4096);
  return analog_value;
}

void loop() {
  nh.spinOnce();
  delay(20);
}
// -------------------------------------------------
