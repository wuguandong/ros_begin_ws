import rospy
from service_demo_py.srv import *

def main():
    rospy.init_node("pyserver")
    server = rospy.Service("pygreetings", Greeting, handler_fun)
    rospy.loginfo("server has ready for request")
    rospy.spin()

def handler_fun(req):
    rospy.loginfo("received. name: %s, age: %d", req.name, req.age)
    return GreetingResponse("i received your request")

if __name__ == "__main__":
    main()