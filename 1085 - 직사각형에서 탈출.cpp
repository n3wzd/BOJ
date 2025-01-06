#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	cout << min(min(abs(x), abs(x - w)), min(abs(y), abs(y - h))) << endl;
	return 0;
}