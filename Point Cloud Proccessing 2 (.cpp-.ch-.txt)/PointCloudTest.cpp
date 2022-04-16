#include<iostream>
#include"PointCloud.h"
#include"Point.h"
using namespace std;

int main()
{
	PointCloud PC1, PC2, PC3;
	PC1.setPointNumb(5);
	PC2.setPointNumb(5);
	list<Point> A, B, C;
	Point a;
	list<Point>::iterator iter1, iter2, iter3;
	for (int i = 0; i < 5; i++)
	{
		a.setX(i);
		a.setY(i + 1);
		a.setZ(i + 2);
		A.push_back(a);
	}
	PC1.setPoints(A);
	A = PC1.getPoints();

	cout << "\n***** A *****" << endl;
	for (iter1 = A.begin(); iter1 != A.end(); iter1++)
		cout << (*iter1).getX() << " " << (*iter1).getY() << " " << (*iter1).getZ() << endl;

	B = A;
	PC2.setPoints(B);
	B = PC2.getPoints();
	cout << endl << "\n***** B *****" << endl;
	for (iter2 = B.begin(); iter2 != B.end(); iter2++)
		cout << (*iter2).getX() << " " << (*iter2).getY() << " " << (*iter2).getZ() << endl;

	PC3 = PC1 + PC2;
	C = PC3.getPoints();
	cout << endl << "\n***** C *****" << endl;
	for (iter3 = C.begin(); iter3 != C.end(); iter3++)
		cout << (*iter3).getX() << " " << (*iter3).getY() << " " << (*iter3).getZ() << endl;

	return 0;
}