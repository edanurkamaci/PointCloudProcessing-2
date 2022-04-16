#include "RadiusOutlierFilter.h"
#include "PointCloud.h"
#include "Point.h"
#include<iostream>
#include"DepthCamera.h"
using namespace std;

int main()
{
	RadiusOutlierFilter ROF;
	PointCloud PC_1, PC_2;
	DepthCamera DC;;
	int  i = 0;
	list<Point> P_1, P_2;
	list<Point>::iterator iter1, iter2;
	DC.setFileName("camera1.txt");
	PC_1 = DC.capture();
	cout << "PC_1 POINT NUMB BEFORE RADIUSOUTLIER FILTER: " << PC_1.getPointNumb() << endl;

	ROF.setRadius(10);
	ROF.filter(PC_1);

	P_1 = PC_1.getPoints();

	cout << "\n********** POINT 1 **********" << PC_1.getPointNumb() << endl;

	for (iter1 = P_1.begin(); iter1 != P_1.end(); iter1++)
	{
		cout << i + 1 << ".  " << iter1->getX() << " " << iter1->getY() << " " << iter1->getZ() << endl;
		i++;
	}
	cout << endl << P_1.size() << " points radius passed through filtering for Camera 1..." << endl;

	DC.setFileName("camera2.txt");
	PC_2 = DC.capture();

	cout << "\nPC_2 POINT NUMB BEFORE RADIUSOUTLIER FILTER: " << PC_2.getPointNumb() << endl;

	ROF.setRadius(10);
	ROF.filter(PC_2);

	i = 0;
	P_2 = PC_2.getPoints();

	cout << "\n********** POINT 2 **********" << PC_2.getPointNumb() << endl;

	for (iter2 = P_2.begin(); iter2 != P_2.end(); iter2++)
	{
		cout << i + 1 << ". Point   " << iter2->getX() << " " << iter2->getY() << " " << iter2->getZ() << endl;
		i++;
	}
	cout << endl << P_2.size() << " points radius passed through filtering for Camera 2..." << endl;

	return 0;
}