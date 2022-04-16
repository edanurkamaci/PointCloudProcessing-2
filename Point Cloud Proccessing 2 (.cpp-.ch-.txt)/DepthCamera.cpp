#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include"Transform.h"
#include"FilterPipe.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include"PointCloudFilter.h"
#include"PassThroughFilter.h"
#include"RadiusOutlierFilter.h"
using namespace std;

DepthCamera::DepthCamera()
{
	this->fileName = "";
}
DepthCamera::~DepthCamera()
{ }
void DepthCamera::setFileName(const string& fileName)
{
	this->fileName = fileName;
}
string DepthCamera::getFileName() const
{
	return this->fileName;
}
PointCloud DepthCamera::capture() 
{
	ifstream inFile;
	int count = 0;
	double data;
	list<Point> *L_1 = new list<Point>;
	PointCloud *PC = new PointCloud;
	Point *p = new Point;

	inFile.open(this->getFileName(), ios::in);
	if (!inFile)
	{
		cout << "ERROR:DepthCamera::capture(): Non Exist File!"<<endl;
		exit(0);
	}
	else
	{
		while (inFile)
		{
			inFile >> data;
			p->setX(data);
			inFile >> data;
			p->setY(data);
			inFile >> data;
			p->setZ(data);
			L_1->push_back(*p);
			count++;
		}
		inFile.close();
		PC->setPointNumb(count-1);
		PC->setPoints(*L_1);
		cout << "\nPoint Numb Before Filters and Transform: " << PC->getPointNumb() << endl << endl;
	}
	return *PC;
}
PointCloud DepthCamera::captureFor()
{
	PointCloud PC;
	PC = this->capture();
	PassThroughFilter PTF;
	RadiusOutlierFilter ROF;
	FilterPipe fp;
	Transform T;
	ROF.setRadius(25);

	fp.addFilter(&ROF);
	fp.addFilter(&PTF);
	if (fileName == "camera1.txt") {

		PTF.setUpperLimitX(400);
		PTF.setLowerLimitX(0);
		PTF.setUpperLimitY(400);
		PTF.setLowerLimitY(0);
		PTF.setUpperLimitZ(45);
		PTF.setLowerLimitZ(-45);

		fp.filterOut(PC);

		T.setAngles(0, 0, -90);
		T.setTrans(100, 500, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());

	}

	else if (fileName == "camera2.txt")
	{
		PTF.setUpperLimitX(500);
		PTF.setLowerLimitX(0);
		PTF.setUpperLimitY(500);
		PTF.setLowerLimitY(0);
		PTF.setUpperLimitZ(45);
		PTF.setLowerLimitZ(-45);

		fp.filterOut(PC);

		T.setAngles(0, 0, 90);
		T.setTrans(550, 150, 50);
		T.setRotation(T.getAngles());
		T.setTranslation(T.getTrans());
	}
	PC = T.doTransform(PC);
	cout << "Point Numb After Filters and Transform: " << PC.getPointNumb() << endl << endl;
	return PC;
}