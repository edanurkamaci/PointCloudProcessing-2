#include <iostream>
#include "DepthCamera.h"
#include "Point.h"
#include "PointCloud.h"
#include <string>
#include "PointCloudRecorder.h"
#include <list>
using namespace std;

int main() {
	DepthCamera DC1, DC2;
	PointCloud PC1, PC2;
	PointCloudRecorder PCR1, PCR2;
	DC1.setFileName("camera1.txt");
	PCR1.setfileName("PointCloudRecorderTestOutput1");
	DC2.setFileName("camera2.txt");
	PCR2.setfileName("PointCloudRecorderTestOutput2");
	PC1 = DC1.capture();
	PC2 = DC2.capture();
	
	cout <<"PC1 POINT NUMB BEFORE POINTCLOUDRECORDER: " << PC1.getPointNumb() << endl;
	cout << "PC2 POINT NUMB BEFORE POINTCLOUDRECORDER: " << PC2.getPointNumb() << endl<<endl;

	bool boolean1, boolean2;
	boolean1 = PCR1.save(PC1);
	boolean2 = PCR2.save(PC2);
	
	return 0;

}