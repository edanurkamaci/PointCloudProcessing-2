#include "Transform.h"
#include <math.h>
#include<iostream>
using namespace std;

void Transform::setAngles(const double& ang1, const double& ang2, const double& ang3)
{
	using namespace Eigen;
	this->angles(0) = ang1;
	this->angles(1) = ang2;
	this->angles(2) = ang3;
}
void Transform::setTrans(const double& transX, const double& transY, const double& transZ)
{
	using namespace Eigen;
	this->trans(0) = transX;
	this->trans(1) = transY;
	this->trans(2) = transZ;
}
Eigen::Vector3d Transform::getAngles() const
{
	return this->angles;
}
Eigen::Vector3d Transform::getTrans() const
{
	return this->trans;
}
void Transform::setRotation(const Eigen::Vector3d& ang)
{
	rotationMatrix(0, 0) = cos(ang(2)) * cos(ang(1));
	rotationMatrix(0, 1) = (cos(ang(2)) * sin(ang(1)) * sin(ang(0))) - (sin(ang(2)) * cos(ang(0)));
	rotationMatrix(0, 2) = (cos(ang(2)) * sin(ang(1)) * cos(ang(0))) + (sin(ang(2)) * sin(ang(0)));
	rotationMatrix(1, 0) = sin(ang(2)) * cos(ang(1));
	rotationMatrix(1, 1) = (sin(ang(2)) * sin(ang(1)) * sin(ang(0))) + (cos(ang(2)) * cos(ang(0)));
	rotationMatrix(1, 2) = (sin(ang(2)) * sin(ang(1)) * cos(ang(0))) - (cos(ang(2)) * sin(ang(0)));
	rotationMatrix(2, 0) = -sin(ang(1));
	rotationMatrix(2, 1) = cos(ang(1)) * sin(ang(0));
	rotationMatrix(2, 2) = cos(ang(1)) * cos(ang(0));
}
void Transform::setTranslation(const Eigen::Vector3d& tr)
{
	using namespace Eigen;
	for (int x = 0; x < 3; x++) {
		for (int y = 0; y < 3; y++) {
			this->transMatrix(x, y) = rotationMatrix(x, y);
		}
	}
	this->transMatrix(3, 0) = 0;
	this->transMatrix(3, 1) = 0;
	this->transMatrix(3, 2) = 0;
	this->transMatrix(3, 3) = 1;
	this->transMatrix(0, 3) = tr(0);
	this->transMatrix(1, 3) = tr(1);
	this->transMatrix(2, 3) = tr(2);
}
list<Point> Transform::doTransform(list<Point>& lp)
{
	list<Point> *TransformedL = new list<Point>;
	list<Point>::iterator iter;
	
	for (iter = lp.begin(); iter != lp.end(); iter++)
	{
		TransformedL->push_back(doTransform(*iter));
	}
	return *TransformedL;
}
Point Transform::doTransform(const Point& p)
{
	Point *Transpoint = new Point;
	double sum = 0;
	Eigen::MatrixXf result(4,1), point(4,1);
	point(0,0) = float(p.getX());
	point(1,0) = float(p.getY());
	point(2,0) = float(p.getZ());
	point(3,0) = 1;


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 1; j++) {
			for (int k = 0; k < 4; k++) {
				sum += (transMatrix(i, k) * point(k,j));
			}
			result(i,j) = float(sum);
			sum = 0;
		}
	}

	Transpoint->setX(result(0,0));
	Transpoint->setY(result(1,0));
	Transpoint->setZ(result(2, 0));

	return *Transpoint;
}
PointCloud Transform::doTransform(const PointCloud& PC)
{
	PointCloud *TransPointCloud= new PointCloud;
	list<Point> P;
	P = PC.getPoints();
	P = doTransform(P);
	
	TransPointCloud->setPoints(P);
	TransPointCloud->setPointNumb(P.size());
	
	cout << "Point Number After Transform: " << P.size() << endl << endl;
	
	return *TransPointCloud;
}