#include"PassThroughFilter.h"
#include"DepthCamera.h"
#include<iostream>
using namespace std;
int main()
{
	PassThroughFilter PTF;
	DepthCamera DC1, DC2;
	PointCloud PC1, PC2;
	string str1 = "camera1.txt", str2 = "camera2.txt";
	DC1.setFileName(str1);
	PC1 = DC1.capture();
	DC2.setFileName(str2);
	PC2 = DC2.capture();

	cout << "***PC1 POINT NUMB: " << PC1.getPointNumb()<<endl;
	cout << "***PC2 POINT NUMB: " << PC1.getPointNumb()<<endl<<endl<<endl;
	//FOR CAMERA 1

	PTF.setUpperLimitX(400);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(400);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);
	PTF.filter(PC1);

	list<Point> Point1, Point2;
	list<Point>::iterator iter1, iter2;
	Point1 = PC1.getPoints();

	cout << "\n********** CAMERA 1 **********" << endl << endl;
	for (iter1 = Point1.begin(); iter1 != Point1.end(); iter1++)
		cout << (*iter1).getX() << " " << (*iter1).getY() << " " << (*iter1).getZ() << endl;

	cout << "------------------------------------------" << endl;

	//FOR CAMERA 2

	PTF.setUpperLimitX(500);
	PTF.setLowerLimitX(0);
	PTF.setUpperLimitY(500);
	PTF.setLowerLimitY(0);
	PTF.setUpperLimitZ(45);
	PTF.setLowerLimitZ(-45);
	PTF.filter(PC2);

	Point2 = PC2.getPoints();
	
	cout << "\n********** CAMERA 2 **********" << endl << endl;
	for (iter2 = Point2.begin(); iter2 != Point2.end(); iter2++)
		cout << (*iter2).getX() << " " << (*iter2).getY() << " " << (*iter2).getZ() << endl;

	cout << "***PC1 POINT NUMB AFTER FILTER: " << Point1.size() << endl;
	cout << "***PC2 POINT NUMB AFTER FILTER: " << Point2.size() << endl << endl << endl;

	return 0;
}