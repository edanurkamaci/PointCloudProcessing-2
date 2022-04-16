#ifndef FILTERPIPE_H
#define FILTERPIPE_H
#include"PointCloudFilter.h"
#include"PointCloud.h"
#include<vector>

class FilterPipe
{
private:
	vector<PointCloudFilter*> filters;
public:
	FilterPipe();
	~FilterPipe();
	void addFilter(PointCloudFilter*);
	void filterOut(PointCloud&);
};
#endif // !FILTERPIPE_H