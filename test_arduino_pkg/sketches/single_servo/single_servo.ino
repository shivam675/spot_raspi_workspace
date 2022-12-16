
#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo FRS;
Servo FRE;
Servo FRW;

Servo FLS;
Servo FLE;
Servo FLW;

Servo RRS;
Servo RRE;
Servo RRW;

Servo RLS;
Servo RLE;
Servo RLW;


// -----------------------------------------------------------------------------
void servo_FR_shoulder( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_elbow( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_wrist( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------








// -----------------------------------------------------------------------------
void servo_FL_shoulder( const std_msgs::UInt16& cmd_msg){
  FLS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FL_elbow( const std_msgs::UInt16& cmd_msg){
  FLE.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FL_wrist( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------








// -----------------------------------------------------------------------------
void servo_FR_shoulder( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_elbow( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_wrist( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------








// -----------------------------------------------------------------------------
void servo_FR_shoulder( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_elbow( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------


// -----------------------------------------------------------------------------
void servo_FR_wrist( const std_msgs::UInt16& cmd_msg){
  FRS.write(cmd_msg.data);
  digitalWrite(13, HIGH-digitalRead(13));
}
ros::Subscriber<std_msgs::UInt16> sub("servo", servo_FR_shoulder);

// -----------------------------------------------------------------------------









void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub);

  FRS.attach(37); //attach it to pin 9
}

void loop(){
  nh.spinOnce();
  delay(1);
}