#!/usr/bin/env python
import tf
import rospy

if __name__ == '__main__':

  rospy.init_node('tf_basic_amr')

  # blink is a contraction of base link
  blink_b = tf.TransformBroadcaster()
  blink_bfprint = tf.TransformBroadcaster()
  bcamera_blink = tf.TransformBroadcaster()
  brplidar_blink = tf.TransformBroadcaster()
  bfcaster_blink = tf.TransformBroadcaster()
  bbcaster_blink = tf.TransformBroadcaster()

  rate = rospy.Rate(50)

  while not rospy.is_shutdown():

    blink_b.sendTransform((0.00, 0.00, 0.00),
        tf.transformations.quaternion_from_euler(0, 0, 0),
        rospy.Time.now(),"base_link","base")

    blink_bfprint.sendTransform((0.00, 0.00, 0.002),
        tf.transformations.quaternion_from_euler(0, 0, 0),
        rospy.Time.now(),"base","base_footprint")

    bcamera_blink.sendTransform((0.04, 0.00, 0.00),
        tf.transformations.quaternion_from_euler(0, 0, 0),
        rospy.Time.now(),"front_camera_link","base_link")

    brplidar_blink.sendTransform((0.00, 0.00, 0.03),
        tf.transformations.quaternion_from_euler(0, 0, 0),
        rospy.Time.now(),"rplidar_link","base_link")

    bfcaster_blink.sendTransform((0.028, 0.00, -0.005),
        tf.transformations.quaternion_from_euler(1.5708, 0, 0),
        rospy.Time.now(),"fcastor_wheel","base_link")

    bbcaster_blink.sendTransform((-0.028, 0.00, -0.005),
        tf.transformations.quaternion_from_euler(1.5708, 0, 0),
        rospy.Time.now(),"bcastor_wheel","base_link")
    rate.sleep()
