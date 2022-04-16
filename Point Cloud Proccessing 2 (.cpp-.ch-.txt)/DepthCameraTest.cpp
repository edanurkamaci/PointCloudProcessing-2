#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include "RadiusOutlierFilter.h"
#include <string>
using namespace std;

int main()
{
	DepthCamera DC;
	PointCloud PC_1, PC_2;

	DC.setFileName("camera1.txt");
	PC_1 = DC.capture();
	list<Point> Point_1, Point_2;
	list<Point>::iterator iter1, iter2;
	Point_1 = PC_1.getPoints();
	iter1 = Point_1.begin();
	cout << "\n********** CAMERA 1 **********" << endl << endl;
	for (iter1 = Point_1.begin(); iter1 != Point_1.end(); iter1++)
		cout << (*iter1).getX() << " " << (*iter1).getY() << " " << (*iter1).getZ() << endl;

	DC.setFileName("camera2.txt");
	PC_2 = DC.capture();
	Point_2 = PC_2.getPoints();
	iter1 = Point_2.begin();
	cout << "-----------------------------------------------------------\n";
	cout << "********** CAMERA 2 **********" << endl << endl;
	for (iter1 = Point_2.begin(); iter1 != Point_2.end(); iter1++)
		cout << (*iter1).getX() << " " << (*iter1).getY() << " " << (*iter1).getZ() << endl;

	return 0;
}