#include <ros/ros.h>
#include <tf/tf.h>
#include <tf/transform_listener.h>

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  //初始化节点
  ros::init(argc, argv, "tf_listener");
  ros::NodeHandle node;

  tf::TransformListener listener;

  //阻塞直到frame相通
  ROS_INFO("等待frame相通..");
  listener.waitForTransform("base_link", "link1", ros::Time(0), ros::Duration(5.0));

  if(listener.canTransform("base_link", "link1", ros::Time(0))){
    tf::StampedTransform stampedtf;

    listener.lookupTransform("base_link", "link1", ros::Time(0), stampedtf);

    ROS_INFO("平移：(%f, %f, %f) 旋转：%f + %fi + %fj + %fk", stampedtf.getOrigin().x(), stampedtf.getOrigin().y(), stampedtf.getOrigin().z(),
             stampedtf.getRotation().w(), stampedtf.getRotation().x(), stampedtf.getRotation().y(), stampedtf.getRotation().z());
  }
  else{
    ROS_INFO("等待frame相通失败!");
  }

  return 0;
}
