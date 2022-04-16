#include "PointCloudRecorder.h"

PointCloudRecorder::PointCloudRecorder()
{
	this->fileName = "";
}
PointCloudRecorder::~PointCloudRecorder()
{

}
void PointCloudRecorder::setfileName(const string& fileName)
{
	this->fileName = fileName;
}
string PointCloudRecorder::getFileName() const 
{
	return this->fileName;
}
bool PointCloudRecorder::save(const PointCloud& PC)
{
	int count = 0;
	ofstream outFile;
	list<Point> *P = new list<Point>;
	*P = PC.getPoints();
	list<Point>::iterator iter;
	outFile.open(fileName + ".txt");

	if (outFile)
	{
		cout << "\nPointCloudRecorder::save: The File Was Opened To Save" << endl;
		
		for (iter = P->begin(); iter != P->end(); iter++)
		{
			outFile <<count+1<<". Point  "<< iter->getX() << " " << iter->getY() << " " << iter->getZ() << endl;
			count++;
		}
		
		cout << "PointCloudRecorder::save: The Datas Were Saved\n" << endl;
		
		outFile.close();
		return 1;
	}
	else {
		cout << "\nERROR:PointCloudRecorder::save: The Save File Could Not Be Opened\n" << endl;
		return 0;
	}
}