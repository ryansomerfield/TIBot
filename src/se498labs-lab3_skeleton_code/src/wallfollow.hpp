#pragma once
#include <ros/ros.h>
#include <std_msgs/UInt8.h> // include for switch
#include <cardriver/infrared.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>  //command publish message type
#include <iostream>
#include <math.h>

#define TEST_SW //uncomment this line to test switches callback
    //message is an 8-bit int. Value of 0 is a pressed switch

#define TEST_IR //uncomment this line to test infrared callback
    //values from 0-127 for r/l
    //values from 0-135 for middle


//#define TEST_IMU//uncomment this line to test imu callback

namespace lab3 { //namespance lab3

class WallFollow
{
private:
  //callback functions:
  void switchCallback(const std_msgs::UInt8::ConstPtr& msg);
  void infraredCallback(const cardriver::infrared::ConstPtr& msg);
  void imuCallback(const sensor_msgs::Imu::ConstPtr& msg);
  void timerCallback(const ros::SteadyTimerEvent& e);
  //private variables:
  bool switches[6] = {0,0,0,0,0,0};
  uint8_t infrared[3] = {0,0,0};
  int16_t angularVel[3] = {0,0,0};
  int16_t linearAccel[3] = {0,0,0};
  int wallFollowInput;
public:
  //functions
  WallFollow(ros::NodeHandle& nh,int input);
  //public variables
  ros::Publisher cmdPub;  // command publisher
  ros::Subscriber swSub, irSub, imuSub; // subscribers
  ros::SteadyTimer timer;

};

} // end of namespace lab3


