#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <string>

class Point
{
private:
	double x;
	double y;
	double z;
public:
	Point();
	void setX(const double&);
	void setY(const double&);
	void setZ(const double&);
	double getX() const;
	double getY() const;
	double getZ() const;
	bool operator==(const Point&) const;
	double distance(const Point&) const;
	~Point() {};
};
#endif // !POINT_H
