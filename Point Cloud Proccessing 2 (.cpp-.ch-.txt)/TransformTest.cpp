#include <iostream>
#include"Transform.h"
#include <vector>
#include <Eigen/Dense>
using namespace std;

int main()
{
	Point P1, P2;
	list<Point> listt;
	P1.setX(150);
	P1.setY(150);
	P1.setZ(-50);
	Transform T;
	PointCloud PC1, PC2;
	
	//FOR TEST 1

	PC1.setPointNumb(2);

	T.setAngles(0, 0, -90.0);
	T.setTrans(100, 500, 50);

	Eigen::Vector3d ang;
	Eigen::Vector3d tr;

	ang = T.getAngles();
	tr = T.getTrans();

	cout << "\n******************** TEST 1 ********************"<<endl<<endl;

	cout << "Angles: " << ang(0) << " " << ang(1) << " " << ang(2) << endl;
	cout << "---------------------------" << endl;
	cout << "Trans: " << tr(0) << " " << tr(1) << " " << tr(2) << endl;
	cout << "---------------------------" << endl;

	T.setRotation(T.getAngles());
	T.setTranslation(T.getTrans());

	cout << "POINT BEFORE TRANSFORM: " << P1.getX() << "  " << P1.getY() << "  " << P1.getZ() << endl;
	cout << "---------------------------" << endl;

	P2 = T.doTransform(P1);//using the function that has point parameter

	cout << "POINT AFTER TRANSFORM: " << P2.getX() << "  " << P2.getY() << "  " << P2.getZ() << endl;
	cout << "---------------------------" << endl;

	P1.setX(150);
	P1.setY(150);
	P1.setZ(-50);
	P2.setX(30);
	P2.setY(60);
	P2.setZ(-100);

	T.setAngles(0, 0, 90.0);
	T.setTrans(550, 150, 50);
	ang = T.getAngles();
	tr = T.getTrans();

	cout << "\n******************** TEST 2 ********************" << endl << endl;

	cout << "Angles: " << ang(0) << " " << ang(1) << " " << ang(2) << endl;
	cout << "---------------------------" << endl;
	cout << "Trans: " << tr(0) << " " << tr(1) << " " << tr(2) << endl;
	cout << "---------------------------" << endl;

	T.setRotation(T.getAngles());
	T.setTranslation(T.getTrans());

	cout << "****** POINT CLOUD 1 (BEFORE TRANSFORM) ******\n\n";
	cout << "Point 1: "<< P1.getX() << " " << P1.getY() << " " << P1.getZ() << endl;
	cout << "---------------------------" << endl;
	cout << "Point 2: " << P2.getX() << " " << P2.getY() << " " << P2.getZ() << endl;
	cout << "---------------------------" << endl;

	listt.push_back(P1);
	listt.push_back(P2);

	PC1.setPoints(listt);

	PC2 = T.doTransform(PC1); //using the function that has pointCloud parameter
	listt = PC2.getPoints();

	cout << "****** POINT CLOUD 2 (AFTER TRANSFORM) ******\n\n";
	cout << "Point 1: " << listt.begin()->getX() << " " << listt.begin()->getY() << " " << listt.begin()->getZ() << endl;
	cout << "---------------------------" << endl;
	cout << "Point 2: " << (++listt.begin())-> getX() << " " << (++listt.begin())-> getY() << " " << (listt.begin()++)-> getZ() << endl;
	cout << "---------------------------" << endl;

	return 0;
	
}