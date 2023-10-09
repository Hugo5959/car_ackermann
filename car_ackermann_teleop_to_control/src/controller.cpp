#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"


float linear_vel = 0.0;
float angular = 0.0;

void chatterCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
  linear_vel = msg->linear.x;
  angular = msg->angular.z;

  linear_vel  = linear_vel / 10;
  angular = angular / 3;
}

int main(int argc, char **argv)
{   
  ros::init(argc, argv, "listener_command");

  ros::NodeHandle n;
  
  ros::Subscriber sub_command = n.subscribe("/robot_command", 1000, chatterCallback);
  ros::Publisher pub_linear  = n.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);
  ros::Publisher pub_angular = n.advertise<std_msgs::Float64>("/car_ackermann/steer_joint_position_controller/command", 1000);
  
  ros::Rate loop_rate(10);

  while (ros::ok())
  {
    
    geometry_msgs::Twist msg_linear;
    std_msgs::Float64 msg_angular;
    
    msg_linear.linear.x = linear_vel;
    msg_angular.data = angular;
    
    pub_linear.publish(msg_linear);
    pub_angular.publish(msg_angular);

    ros::spinOnce();

    loop_rate.sleep();
    
  }
  return 0;
}