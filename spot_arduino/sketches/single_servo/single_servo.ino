
#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo sub_one;
Servo sub_two;

void sub_one_call_back( const std_msgs::UInt16& cmd_msg){
  sub_one.write(cmd_msg.data); //set sub_1 angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}

void sub_two_call_back( const std_msgs::UInt16& cmd_msg){
  sub_one.write(cmd_msg.data); //set sub_1 angle, should be from 0-180  
  digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}



ros::Subscriber<std_msgs::UInt16> sub_one_object("sub_one", sub_one_call_back);
ros::Subscriber<std_msgs::UInt16> sub_two_object("sub_two", sub_two_call_back);


void setup(){
  pinMode(13, OUTPUT);

  nh.initNode();
  nh.subscribe(sub_one_object);
  nh.subscribe(sub_two_object);
  
  sub_one.attach(9); //attach it to pin 9
  sub_two.attach(10); //attach it to pin 9x x 
}

void loop(){
  nh.spinOnce();
  delay(10);
}