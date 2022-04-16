#ifndef POINTCLOUDRECORDER_H
#define POINTCLOUDRECORDER_H
#include "PointCloud.h"
#include "Point.h"
#include "DepthCamera.h"
#include <fstream>
#include <string>
using namespace std;

class PointCloudRecorder
{
private:
	string fileName;
public:
	PointCloudRecorder();
	~PointCloudRecorder();
	void setfileName(const string& fileName);
	string getFileName() const;
	bool save(const PointCloud& PC);
};
#endif // !POINTCLOUDRECORDER_H

