// std
    #include <string>
    #include <iostream>
// pc
	#include <sensor_msgs/PointCloud2.h>
// tf
	#include <tf/transform_listener.h>
    #include <tf/transform_broadcaster.h>
// custom
    #include <geometry/Line.h>
    #include <geometry/Plane.h>
    #include <geometry/PointCloud.h>

bool tf_exists(tf::TransformListener* tf_listener, tf::StampedTransform* tf, std::string name);