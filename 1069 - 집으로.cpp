#include <iostream>
#include <cmath>
typedef double d;
using namespace std;

d X, Y, D, T, cost = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> X >> Y >> D >> T;
	d dist = sqrt(X * X + Y * Y);

	if (D < dist)
	{
		d remain = dist - floor(dist / D) * D;
		cost = floor(dist / D) * T + min(remain, T);
	}
	else
	{
		d remain = D - dist;
		cost = T + min(remain, T);
	}
	cost = min(dist, cost);

	cout << fixed, cout.precision(9);
	cout << cost;
	return 0;
}
