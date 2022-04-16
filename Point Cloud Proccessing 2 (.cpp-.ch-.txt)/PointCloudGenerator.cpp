#include"PointCloudGenerator.h"

PointCloudGenerator::PointCloudGenerator()
{ 
	filterPipe = new FilterPipe();
}
PointCloudGenerator::~PointCloudGenerator()
{ 

}
void PointCloudGenerator::setFilterPipe(FilterPipe* fp)
{
	this->filterPipe = fp;
}
void PointCloudGenerator::setTransform(const Transform& t)
{
	this->transform = t;
}
Transform PointCloudGenerator::getTransform() const
{
	return this->transform;
}