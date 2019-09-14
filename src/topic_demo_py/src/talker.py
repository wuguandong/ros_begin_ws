import rospy
from topic_demo_py.msg import gps

def talker():
  rospy.init_node("pytalker")

  pub = rospy.Publisher("gps_info", gps, queue_size = 10)

  rate = rospy.Rate(1)

  while not rospy.is_shutdown():
    pub.publish(gps(1.0, 1.0, "working"))
    rospy.loginfo("sending...")
    rate.sleep()

if __name__ == "__main__":
  talker()
