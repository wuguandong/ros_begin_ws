import rospy
from topic_demo_py.msg import gps

def dealMsg(gps):
    rospy.loginfo("get gps info:")

def listener():
    rospy.init_node("pylistener")

    rospy.Subscriber("gps_info", gps, dealMsg)

    rospy.spin()

if __name__ == "__main__":
    listener()