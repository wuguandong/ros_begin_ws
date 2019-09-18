#include <ros/ros.h>  //包含ros命名空间
#include <tf/tf.h>  //包含tf命名空间
#include <tf/transform_broadcaster.h>  //包含tf命名空间里的TransformBroadcaster类

int main(int argc, char** argv){
  setlocale(LC_ALL, "");

  //初始化节点
  ros::init(argc, argv, "tf_broadcaster");
  ros::NodeHandle node;

  tf::TransformBroadcaster br;

  tf::Transform transform;
  //设置变换的平移
  tf::Vector3 v(1, 2, 3);
  transform.setOrigin(v);
  //设置变换的旋转
  tf::Quaternion q;
  q.setRPY(0, 0, 0);
  transform.setRotation(q);

  ros::Rate rate(1);
  while(ros::ok()){
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "base_link", "link1"));
    ROS_INFO("发布了变换");
    rate.sleep();
  }

  return 0;
}
