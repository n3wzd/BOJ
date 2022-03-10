#include <iostream>
using namespace std;

int main()
{
	int x, y, r;
	cin >> x >> y;
	if (x > 0 && y > 0) r = 1;
	if (x < 0 && y > 0) r = 2;
	if (x < 0 && y < 0) r = 3;
	if (x > 0 && y < 0) r = 4;
	cout << r << endl;
	return 0;
}