#include "Point.h"
#include "PointCloud.h"
#include "DepthCamera.h"
#include "Transform.h"
#include "RadiusOutlierFilter.h"
#include "PassThroughFilter.h"
#include "PointCloudRecorder.h"
#include"PointCloudInterface.h"
#include <iostream>

int main(void)
{
	PointCloudRecorder PCR;
	DepthCamera DC1, DC2;
	PointCloudInterface PCI;
	DC1.setFileName("camera1.txt");
	DC2.setFileName("camera2.txt");

	PCI.addGenerator(&DC1);
	PCI.addGenerator(&DC2);

	PCI.setRecorder(&PCR);

	PCI.generate();
	PCI.record();

	system("pause");
	return 0;
}
