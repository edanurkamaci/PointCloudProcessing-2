#include"FilterPipe.h"

FilterPipe::FilterPipe()
{}
FilterPipe::~FilterPipe()
{}
void FilterPipe::addFilter(PointCloudFilter* filter)
{
	this->filters.push_back(filter);
}
void FilterPipe::filterOut(PointCloud& pc)
{
	for (int i = 0; i < int(this->filters.size()); i++)
		this->filters[i]->filter(pc);
}