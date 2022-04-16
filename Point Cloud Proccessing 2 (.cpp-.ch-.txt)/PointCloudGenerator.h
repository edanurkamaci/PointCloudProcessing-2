#ifndef POINTCLOUDGENERATOR_H
#define POINTCLOUDGENERATOR_H
#include"Transform.h"
#include"FilterPipe.h"

class PointCloudGenerator
{
private:
	Transform transform;
	FilterPipe* filterPipe;
public:
	PointCloudGenerator();
	~PointCloudGenerator();
	virtual PointCloud capture()=0;
	virtual PointCloud captureFor()=0;
	void setFilterPipe(FilterPipe*);
	void setTransform(const Transform&);
	Transform getTransform() const;
};


#endif // !POINTCLOUDGENERATOR_H
