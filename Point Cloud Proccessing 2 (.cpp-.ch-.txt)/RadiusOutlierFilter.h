#ifndef RADIUSOUTLIERFILTER_H
#define RADIUSOUTLIERFILTER_H
#include "PointCloud.h"
#include "Point.h"
#include "PointCloudFilter.h"

class RadiusOutlierFilter: virtual public PointCloudFilter
{
private:
	double radius;
public:
	RadiusOutlierFilter();
	~RadiusOutlierFilter();
	void setRadius(const double&);
	double getRadius() const;
	void filter(PointCloud&);
};
#endif // !RADIUSOUTLIERFILTER_H

