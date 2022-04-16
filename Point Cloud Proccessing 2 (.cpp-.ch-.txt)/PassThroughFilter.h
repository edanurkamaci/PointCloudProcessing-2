#ifndef PASSTHROUGHFILTER_H
#define PASSTHROUGHFILTER_H
#include"PointCloud.h"
#include"DepthCamera.h"
#include "PointCloudFilter.h"

class PassThroughFilter: virtual public PointCloudFilter
{
private:
	double upperLimitX;/*!< highest limit for point X */
	double lowerLimitX;/*!< lowest limit for point X */
	double upperLimitY;/*!< highest limit for point Y */
	double lowerLimitY;/*!< lowest limit for point Y */
	double upperLimitZ;/*!< highest limit for point X */
	double lowerLimitZ;/*!< lowest limit for point Y */
public:
	PassThroughFilter();
	~PassThroughFilter();
	void setUpperLimitX(const double&);
	double getUpperLimitX() const;
	void setLowerLimitX(const double&);
	double getLowerLimitX() const;
	void setUpperLimitY(const double&);
	double getUpperLimitY() const;
	void setLowerLimitY(const double&);
	double getLowerLimitY() const;
	void setUpperLimitZ(const double&);
	double getUpperLimitZ() const;
	void setLowerLimitZ(const double&);
	double getLowerLimitZ() const;
	void filter(PointCloud&);
};

#endif //PASSTHROUGHFILTER_H