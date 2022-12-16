
#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#include <Servo.h>
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo flls;
Servo flle;
Servo fllw;

Servo frls;
Servo frle;
Servo frlw;

Servo rlls;
Servo rlle;
Servo rllw;

Servo rrls;
Servo rrle;
Servo rrlw;

int voltage_control = 127;
// Motor A connections
int enA = 3;
int in1 = 24;
int in2 = 25;
// Motor B connections
int enB = 4;
int in3 = 26;
int in4 = 27;

//set servo angle, should be from 0-180
void flls_callback( const std_msgs::UInt16& cmd_msg) {
  flls.write(cmd_msg.data);
  }
void flle_callback( const std_msgs::UInt16& cmd_msg) {
  flle.write(cmd_msg.data);
  }
void fllw_callback( const std_msgs::UInt16& cmd_msg) {
  fllw.write(cmd_msg.data);
  }

void frls_callback( const std_msgs::UInt16& cmd_msg) {
  frls.write(cmd_msg.data);
  }
void frle_callback( const std_msgs::UInt16& cmd_msg) {
  frle.write(cmd_msg.data);
  }
void frlw_callback( const std_msgs::UInt16& cmd_msg) {
  frlw.write(cmd_msg.data);
  }

void rlls_callback( const std_msgs::UInt16& cmd_msg) {
  rlls.write(cmd_msg.data);
  }
void rlle_callback( const std_msgs::UInt16& cmd_msg) {
  rlle.write(cmd_msg.data);
  }
void rllw_callback( const std_msgs::UInt16& cmd_msg) {
  rllw.write(cmd_msg.data);
  }

void rrls_callback( const std_msgs::UInt16& cmd_msg) {
  rrls.write(cmd_msg.data);
  }
void rrle_callback( const std_msgs::UInt16& cmd_msg) {
  rrle.write(cmd_msg.data);
  }
void rrlw_callback( const std_msgs::UInt16& cmd_msg) {
  rrlw.write(cmd_msg.data);
  }

// Front Left Leg
ros::Subscriber<std_msgs::UInt16> flls_sub("front_left_leg_shoulder", flls_callback);
ros::Subscriber<std_msgs::UInt16> flle_sub("front_left_leg_elbow", flle_callback);
ros::Subscriber<std_msgs::UInt16> fllw_sub("front_left_leg_wrist", fllw_callback);

// Front Right Leg
ros::Subscriber<std_msgs::UInt16> frls_sub("front_right_leg_shoulder", frls_callback);
ros::Subscriber<std_msgs::UInt16> frle_sub("front_right_leg_elbow", frle_callback);
ros::Subscriber<std_msgs::UInt16> frlw_sub("front_right_leg_wrist", frlw_callback);

// Rear Right Leg
ros::Subscriber<std_msgs::UInt16> rlls_sub("rear_left_leg_shoulder", rlls_callback);
ros::Subscriber<std_msgs::UInt16> rlle_sub("rear_left_leg_elbow", rlle_callback);
ros::Subscriber<std_msgs::UInt16> rllw_sub("rear_left_leg_wrist", rllw_callback);

// Rear Right Leg
ros::Subscriber<std_msgs::UInt16> rrls_sub("rear_right_leg_shoulder", rrls_callback);
ros::Subscriber<std_msgs::UInt16> rrle_sub("rear_right_leg_elbow", rrle_callback);
ros::Subscriber<std_msgs::UInt16> rrlw_sub("rear_right_leg_wrist", rrlw_callback);

void setup() {
  pinMode(13, OUTPUT);

  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);

  analogWrite(enA, voltage_control);
  analogWrite(enB, voltage_control);

  nh.initNode();
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

  flls.attach(37); //attach it to pin 3
  flle.attach(35); //attach it to pin 4
  fllw.attach(34); //attach it to pin 5

  frls.attach(38); //attach it to pin 6
  frle.attach(39); //attach it to pin 7
  frlw.attach(36); //attach it to pin 8
  
  rlls.attach(52); //attach it to pin 9
  rlle.attach(53); //attach it to pin 10
  rllw.attach(50); //attach it to pin 11
  
  rrls.attach(48); //attach it to pin 12
  rrle.attach(48); //attach it to pin 13
  rrlw.attach(51); //attach it to pin 14

}

void loop() {
  nh.spinOnce();
  delay(20);
}
