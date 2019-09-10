#include <ros/ros.h>
#include <topic_demo/gps.h>

int main(int argc, char** argv){
  setlocale(LC_ALL, "zh_CN.UTF-8");

  ros::init(argc, argv, "talker");
  ros::NodeHandle nh;

  topic_demo::gps msg;
  msg.x = 1.0;
  msg.y = 1.0;
  msg.status = "working";

  ros::Publisher pub = nh.advertise<topic_demo::gps>("gps_info", 1);

  ros::Rate r(1.0);

  while(ros::ok()){
    ROS_INFO("发布者: x=%f y=%f", msg.x, msg.y);
    pub.publish(msg);
  }

  return 0;
}
