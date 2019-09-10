#include <ros/ros.h>
#include <service_demo/Greeting.h>

bool handle_function(service_demo::Greeting::Request &req, service_demo::Greeting::Response &res);

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "server");
  ros::NodeHandle nh;

  ros::ServiceServer server = nh.advertiseService("greetings", handle_function);

  ros::spin();

  return 0;
}

bool handle_function(service_demo::Greeting::Request &req, service_demo::Greeting::Response &res){
  setlocale(LC_ALL, "");

  //显示请求的消息
  ROS_INFO("服务器：收到请求，姓名：%s，年龄: %d .", req.name.c_str(), req.age);

  //处理请求
  res.feedback = "你好 " + req.name + " ，我是服务器！";

  //返回true，表示正确处理了请求
  return true;
}
