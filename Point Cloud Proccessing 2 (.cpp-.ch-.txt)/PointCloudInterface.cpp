#include"PointCloudInterface.h"

PointCloudInterface::PointCloudInterface()
{ }

PointCloudInterface::~PointCloudInterface()
{ }

void PointCloudInterface::addGenerator(PointCloudGenerator* generators)
{
	this->generators.push_back(generators);
}
void PointCloudInterface::setRecorder(PointCloudRecorder* recorder)
{
	this->recorder = recorder;
}
bool PointCloudInterface::generate()
{
	if (generators.size() == 0)
		return false;
	else
	{
		for (int i = 0; i < int(generators.size()); i++)
		{
			this->patch = generators[i]->captureFor();
			this->pointCloud = this->pointCloud + this->patch;
		}
		cout << "Point Number in the PointCloud After Generate: " << pointCloud.getPointNumb() << endl << endl;
		return true;
	}
}
bool PointCloudInterface::record() 
{
	this->recorder->setfileName("LAST POINTS");
	this->recorder->save(pointCloud);
	return true;
}