#ifndef POINTCLOUDFILTER_H
#define POINTCLOUDFILTER_H
#include"PointCloud.h"

class PointCloudFilter
{
public:
	PointCloudFilter();
	~PointCloudFilter();
	virtual void filter(PointCloud&) = 0;
};

#endif // !POINTCLOUDFILTER_H