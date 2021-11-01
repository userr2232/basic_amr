#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
ros::init(argc, argv, "talker");
ros::NodeHandle n;
ros::Publisher cmd_vel_pub = n.advertise<geometry_msgs::Twist>("cmd_vel", 1);
ros::Rate loop_rate(1);
    int i = 0;
    int sign = 1;
    while (ros::ok() && i++ < 5) {
        geometry_msgs::Twist vel;
        vel.angular.z = sign * 0.2;
        sign *= -1;
        cmd_vel_pub.publish(vel);
        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0;
}