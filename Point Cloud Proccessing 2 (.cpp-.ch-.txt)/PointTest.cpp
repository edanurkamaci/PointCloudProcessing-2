#include<iostream>
#include"Point.h"
using namespace std;

int main()
{
	Point P1, P2;
	P1.setX(1);
	P1.setY(2);
	P1.setZ(3);

	P2.setX(1);
	P2.setY(5);
	P2.setZ(10);

	cout << "P1 x->" << P1.getX() << " y->" << P1.getY() << " z->" << P1.getZ() << endl;
	cout << "P2 x->" << P2.getX() << " y->" << P2.getY() << " z->" << P2.getZ() << endl;

	if (P1 == P2)
		cout << "\nP1 POINT IS EQUAL TO P2 POINT." << endl;
	else
		cout << "\nP1 POINT IS NOT EQUAL TO P2 POINT!" << endl;

	cout << "\nTHE DISTANCE BETWEEN P1 and P2 POINTS -> " << P1.distance(P2) << endl;

	return 0;
}