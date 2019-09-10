#include <ros/ros.h>
#include <service_demo/Greeting.h>

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "client");
  ros::NodeHandle nh;

  ros::ServiceClient client = nh.serviceClient<service_demo::Greeting>("greetings");

  service_demo::Greeting srv;
  srv.request.name = "雷军";
  srv.request.age = 42;

  if(client.call(srv)){
    ROS_INFO("收到服务器的答复：%s", srv.response.feedback.c_str());
  }
  else{
    ROS_INFO("失败!");
  }

  return 0;
}
