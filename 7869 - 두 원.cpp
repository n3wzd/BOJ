#include <iostream>
#include <cmath>
#define PI 3.14159265358979323846
using namespace std;

double px1, py1, r1, px2, py2, r2;
double A;

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Swap(double* a, double* b)
{
	double t = *a;
	*a = *b, *b = t;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> px1 >> py1 >> r1 >> px2 >> py2 >> r2;
	if (r1 < r2) // r1 > r2
		Swap(&px1, &px2), Swap(&py1, &py2), Swap(&r1, &r2);

	double D = Distance(px1, py1, px2, py2);
	if (D >= r1 + r2) A = 0;
	else if (D <= r1 - r2) A = r2 * r2 * PI;
	else
	{
		double ang1, ang2, sector1, sector2, tri1, tri2;
		ang1 = acos((r1 * r1 + D * D - r2 * r2) / (2 * r1 * D));
		ang2 = acos((r2 * r2 + D * D - r1 * r1) / (2 * r2 * D));

		sector1 = r1 * r1 * ang1;
		sector2 = r2 * r2 * ang2;
		
		tri1 = r1 * r1 * sin(ang1 * 2) / 2;
		tri2 = r2 * r2 * sin(min(ang2, (PI - ang2)) * 2) / 2;

		if (D * D > r1 * r1 - r2 * r2) A = (sector1 - tri1) + (sector2 - tri2);
		else A = (sector1 - tri1) + (sector2 + tri2);
	}

	cout << fixed, cout.precision(3);
	cout << round(A * 1000) / 1000;
	return 0;
}