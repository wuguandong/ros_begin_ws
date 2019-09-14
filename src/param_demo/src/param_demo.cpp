#include <ros/ros.h>

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  ros::init(argc, argv, "param_demo");
  ros::NodeHandle nh;
//  int parameter1, parameter2, parameter3, parameter4, parameter5;

  //获取参数
//  ros::param::get("param1", parameter1);
//  nh.getParam("param2", parameter2);
//  nh.param("param3", parameter3, 123); //123是默认值

  //设置参数
//  ros::param::set("param4", parameter4);
//  nh.setParam("param5", parameter5);

  //检查参数是否存在
//  ros::param::has("param5");
//  nh.hasParam("param6");

  //删除参数
//  ros::param::del("param5");
//  nh.deleteParam("param6");

  int a = 100;
  ros::param::set("a", a);
  if(ros::param::has("a")){
    int a2;
    ros::param::get("a", a2);
    ROS_INFO("参数a：%d", a2);
  }

  int b = 200;
  nh.setParam("b", b);
  if(nh.hasParam("b")){
    int b2;
    nh.getParam("b", b2);
    ROS_INFO("参数b：%d", b2);
  }

  return 0;
}
