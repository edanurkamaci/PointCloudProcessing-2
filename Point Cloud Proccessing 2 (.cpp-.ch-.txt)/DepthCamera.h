#ifndef DEPTHCAMERA_H
#define DEPTHCAMERA_H
#include "PointCloud.h"
#include"PointCloudGenerator.h"
#include <string>
#include <fstream>

class DepthCamera : virtual public PointCloudGenerator
{
private:
	string fileName;
public:
	DepthCamera();
	~DepthCamera();
	void setFileName(const string&);
	string getFileName() const;
	PointCloud capture();
	PointCloud captureFor();
};
#endif // !DEPTHCAMERA_H
