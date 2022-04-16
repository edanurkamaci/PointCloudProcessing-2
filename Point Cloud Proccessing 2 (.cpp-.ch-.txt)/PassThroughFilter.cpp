#include"PassThroughFilter.h"
#include<iostream>
using namespace std;

PassThroughFilter::PassThroughFilter()
{
	this->upperLimitX = 0;
	this->lowerLimitX = 0;
	this->upperLimitY = 0;
	this->lowerLimitY = 0;
	this->upperLimitZ = 0;
	this->lowerLimitZ = 0;
}
PassThroughFilter::~PassThroughFilter()
{
}
void PassThroughFilter::setUpperLimitX(const double& upperLimitX)
{
	this->upperLimitX = upperLimitX;
}
double PassThroughFilter::getUpperLimitX() const
{
	return this->upperLimitX;
}
void PassThroughFilter::setLowerLimitX(const double& LowerLimitX)
{
	this->lowerLimitX = LowerLimitX;
}
double PassThroughFilter::getLowerLimitX() const
{
	return this->lowerLimitX;
}
void PassThroughFilter::setUpperLimitY(const double& upperLimitY)
{
	this->upperLimitY = upperLimitY;
}
double PassThroughFilter::getUpperLimitY() const
{
	return this->upperLimitY;
}
void PassThroughFilter::setLowerLimitY(const double& LowerLimitY)
{
	this->lowerLimitY = LowerLimitY;
}
double PassThroughFilter::getLowerLimitY() const
{
	return this->lowerLimitY;
}
void PassThroughFilter::setUpperLimitZ(const double& upperLimitZ)
{
	this->upperLimitZ = upperLimitZ;
}
double PassThroughFilter::getUpperLimitZ() const
{
	return this->upperLimitZ;
}
void PassThroughFilter::setLowerLimitZ(const double& LowerLimitZ)
{
	this->lowerLimitZ = LowerLimitZ;
}
double PassThroughFilter::getLowerLimitZ() const
{
	return this->lowerLimitZ;
}
void PassThroughFilter::filter(PointCloud& PC) {
	int count = 0;
	list<Point> L1, L2;
	list<Point>::iterator iter;
	L1 = PC.getPoints();

	for (iter = L1.begin(); iter != L1.end(); iter++)
	{
		if (((*iter).getX() <= this->getUpperLimitX() && (*iter).getX() >= this->getLowerLimitX()) &&
			(((*iter).getY() <= this->getUpperLimitY() && (*iter).getY() >= this->getLowerLimitY())) &&
			((*iter).getZ() <= this->getUpperLimitZ() && (*iter).getZ() >= this->getLowerLimitZ()))
		{
			L2.push_back(*iter);
			count++;
		}
	}
	PC.setPoints(L2);
	PC.setPointNumb(count);
	cout << "Point Number After PassThrough Filter: " << count<<endl<<endl;
}