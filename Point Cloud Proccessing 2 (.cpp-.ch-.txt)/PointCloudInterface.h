#ifndef POINTCLOUDINTERFACE_H
#define POINTCLOUDINTERFACE_H
#include"PointCloud.h"
#include"DepthCamera.h"
#include"PointCloudGenerator.h"
#include"PointCloudRecorder.h"
#include<vector>

class PointCloudInterface
{
private:
	PointCloud pointCloud;
	PointCloud patch ;
	vector<PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
public:
	PointCloudInterface();
	~PointCloudInterface();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool record();
};

#endif // !POINTCLOUDINTERFACE_H