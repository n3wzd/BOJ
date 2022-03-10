#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int d1, d2, d3, res = 0;
	cin >> d1 >> d2 >> d3;

	if (d1 == d2 && d2 == d3) res = 10000 + d1 * 1000;
	else if (d1 == d2 || d1 == d3) res = 1000 + d1 * 100;
	else if (d2 == d3) res = 1000 + d2 * 100;
	else res = max(max(d1, d2), d3) * 100;

	cout << res;
	return 0;
}