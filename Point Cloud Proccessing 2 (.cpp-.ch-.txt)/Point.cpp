#include "Point.h"
#include<iostream>
#include<math.h>
using namespace std;

Point::Point()
{
	x = 0;
	y = 0;
	z = 0;
}
void Point::setX(const double& x)
{
	this->x = x;
}
void Point::setY(const double& y)
{
	this->y = y;
}
void Point::setZ(const double& z)
{
	this->z = z;
}
double Point::getX()const
{
	return this->x;
}
double Point::getY()const
{
	return this->y;
}
double Point::getZ() const
{
	return this->z;
}
bool Point::operator==(const Point& Point) const
{
	if (this->x == Point.x && this->y == Point.y && this->z == Point.z)
		return true;
	else
		return false;
}
double Point::distance(const Point& Point) const
{
	double distance;
	distance = sqrt(pow(Point.x - this->x, 2) + pow(Point.y - this->y, 2) + pow(Point.z - this->z, 2));
	return distance;
}