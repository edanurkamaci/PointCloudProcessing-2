#include "PointCloud.h"

PointCloud::PointCloud()
{
	pointNumber = 0;
}
PointCloud::~PointCloud()
{
}
void PointCloud::setPoints(const list<Point>& p)
{
	this->points = p;
}
void PointCloud::setPointNumb(const int& a)
{
	pointNumber = a;
}
list<Point> PointCloud::getPoints() const
{
	return points;
}
int PointCloud::getPointNumb() const
{
	return this->pointNumber;
}
PointCloud PointCloud::operator+(const PointCloud& PC)
{
	list<Point> L_1, L_2, temp;
	list<Point>::iterator iter1, iter2;
	PointCloud Pc;
	L_1 = this->getPoints();
	L_2 = PC.getPoints();
	unsigned int j = 0;
	iter1 = L_1.begin();
	iter2 = L_2.begin();
	int a = L_1.size();
	unsigned int i = 0;
	while(i < L_1.size() + L_2.size()) 
	{
		if (i < L_1.size())
			temp.push_back(*iter1++);
		else
			temp.push_back(*iter2++);
		i++;
	}
	Pc.setPointNumb(L_1.size() + L_2.size());
	Pc.setPoints(temp);
	return Pc;
}
void PointCloud::operator=(PointCloud* PC)
{
	list<Point>::iterator iter;

	for (iter = PC->points.begin(); iter != PC->points.end(); iter++)
	{
		this->points.push_back(*iter);
	}
}