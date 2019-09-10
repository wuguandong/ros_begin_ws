#include <ros/ros.h>
#include <topic_demo/gps.h>

void gpsCallback(const topic_demo::gps::ConstPtr &msg);

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "listener");
  ros::NodeHandle nh;

  ros::Subscriber sub = nh.subscribe("gps_info", 1, gpsCallback);

  ros::spin();

  return 0;
}

void gpsCallback(const topic_demo::gps::ConstPtr &msg){
  ROS_INFO("订阅者：收到gps信息 x=%f y=%f", msg->x, msg->y);
}
