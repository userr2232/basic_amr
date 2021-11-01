#include "ros/ros.h"
#include "geometry_msgs/PoseWithCovarianceStamped.h"

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_posearray");
  ros::NodeHandle n;
  ros::Publisher pub = n.advertise<geometry_msgs::PoseWithCovariance>("amcl_pose", 1);
  ros::Rate loop_rate(1);
    int i = 0;
    float cov[36] = {0.24741818976460825, -0.0018966521679125783, 0.0, 0.0, 0.0, 0.0, -0.00189665216791258, 0.2348719316431109, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.06919473224799318};
  while (ros::ok() && i++ < 5)
  {
    geometry_msgs::PoseWithCovariance pose0;
    pose0.pose.position.x = 0.5;
    pose0.pose.position.y = 0.02;
    pose0.pose.orientation.z = 0.7071;
    pose0.pose.orientation.w = 0.7071;
    
    for(int j = 0; j < 36; ++j) pose0.covariance[j] = cov[j];
    pub.publish(pose0);
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}