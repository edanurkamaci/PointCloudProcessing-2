#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include "Point.h"
#include <list>
using namespace std;

class PointCloud
{
private:
	list<Point> points;
	int pointNumber;
public:
	PointCloud();
	void setPoints(const list<Point>&);
	void setPointNumb(const int&);
	list<Point> getPoints() const;
	int getPointNumb() const;
	PointCloud operator+(const PointCloud&);
	void operator=(PointCloud*);
	~PointCloud();

};
#endif // !POINTCLOUD_H
