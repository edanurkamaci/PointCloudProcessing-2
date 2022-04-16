#include "RadiusOutlierFilter.h"
RadiusOutlierFilter::RadiusOutlierFilter()
{
	this->radius = 0;
}
RadiusOutlierFilter::~RadiusOutlierFilter()
{ }
void RadiusOutlierFilter::setRadius(const double& _radius)
{
	this->radius = _radius;
}
double RadiusOutlierFilter::getRadius() const
{
	return this->radius;
}
void RadiusOutlierFilter::filter(PointCloud& PC)
{
	list<Point> L1, L2;
	list<Point>::iterator iter1;
	list<Point>::iterator iter2;
	int count = 0;
	L1 = PC.getPoints();
	
	for (iter1 = L1.begin(); iter1 != L1.end(); iter1++)
	{
		for (iter2 = L1.begin(); iter2 != L1.end(); iter2++)
		{
			if ((*iter1).distance(*iter2) < getRadius() && iter1 != iter2)
			{
				L2.push_back(*iter1);
				count++;
				break;
			}
		}
	}
	PC.setPointNumb(count);
	PC.setPoints(L2);
	cout << "Point Number After Radiusoutlier Filter: " << count << endl << endl;
}