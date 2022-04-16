#pragma once
#include "Point.h"
#include "PointCloud.h"
#include <Eigen/Dense>

class Transform
{
private:
	Eigen::Vector3d angles;
	Eigen::Vector3d trans;
	Eigen::Matrix4d transMatrix;
	Eigen::Matrix3d rotationMatrix;
	int count;
public:
	Transform() {};
	~Transform() {};
	void setAngles(const double&, const double&, const double&);
	void setTrans(const double&, const double&, const double&);
	Eigen::Vector3d getAngles() const;
	Eigen::Vector3d getTrans() const;
	void setRotation(const Eigen::Vector3d&);
	void setTranslation(const Eigen::Vector3d&);
	Point doTransform(const Point&);
	list<Point> doTransform(list<Point>&);
	PointCloud doTransform(const PointCloud&);
};