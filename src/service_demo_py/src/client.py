import rospy
from service_demo_py.srv import *

def main():
    rospy.init_node("pyclient")
    rospy.wait_for_service("pygreetings")

    proxy = rospy.ServiceProxy("pygreetings", Greeting)

    req = GreetingRequest("wuguandong", 24)

    res =  proxy.call(req)

    rospy.loginfo(res.feedback)


if __name__ == "__main__":
    main()