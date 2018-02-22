// std
	#include <string>
	#include <iostream>
// ros
	#include <ros/console.h>
// point cloud
	#include <pcl_conversions/pcl_conversions.h>
	#include <pcl/point_cloud.h>
	#include <pcl/impl/point_types.hpp>
	#include <sensor_msgs/PointCloud2.h>
	#include <pcl_ros/transforms.h>
	#include <pcl/filters/voxel_grid.h>
	#include <pcl/filters/radius_outlier_removal.h>
	#include <pcl/filters/passthrough.h>
// tf
	#include <tf/LinearMath/Transform.h>
	#include <tf_conversions/tf_eigen.h>
	#include <tf/transform_listener.h>
	#include <tf/transform_broadcaster.h>
// dynamic reconfigure
	#include <dynamic_reconfigure/server.h>
	#include <pcl_ros/FilterConfig.h>

const std::string REFERENCE_FRAME = "cam_center";

struct cutting_axis_t
{
	bool enable;
	float bounds[2];
};
struct cutting_t
{
	cutting_axis_t x;
	cutting_axis_t y;
	cutting_axis_t z;
};
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

namespace geometry
{
	class PointCloud
	{
		private:
			std::string name;
			pcl::PCLPointCloud2* cloud;
        	const tf::TransformListener* tf_listener;

			// parameters
				// subsampling
					double subsize;
				//cutting
					cutting_t cutting;
				// radius filtering
					bool filtering;
					double filter_radius;
					int filter_min_neighbors;
		public:
			// constructors
				PointCloud();

			// init 
				void init(tf::TransformListener* listener);

			// getters
				sensor_msgs::PointCloud2* get_pc();

			// // update
				void update(const sensor_msgs::PointCloud2ConstPtr& cloud);

			// processing
				void subsample();
				void radius_filter();
				void cut();
	};
}