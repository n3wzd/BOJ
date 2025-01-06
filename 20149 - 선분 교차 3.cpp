#include <iostream>
#include <cmath>
typedef long long ll;
typedef double dd;
using namespace std;

typedef struct Point {
	ll x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	ll D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

ll Sign(ll n)
{
	return (n == 0) ? 0 : ((n > 0) ? 1 : -1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Point p1, p2, p3, p4;
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;
	int r1 = CCW(p1, p2, p3), r2 = CCW(p1, p2, p4);
	int r3 = CCW(p3, p4, p1), r4 = CCW(p3, p4, p2);
	int res;

	if (r1 == 0 || r2 == 0 || r3 == 0 || r4 == 0)
	{
		if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0)
		{
			ll ranx1 = min(p1.x, p2.x), ranx2 = max(p1.x, p2.x);
			ll rany1 = min(p1.y, p2.y), rany2 = max(p1.y, p2.y);
			ll ranx3 = min(p3.x, p4.x), ranx4 = max(p3.x, p4.x);
			ll rany3 = min(p3.y, p4.y), rany4 = max(p3.y, p4.y);

			res = (p3.x >= ranx1 && p3.x <= ranx2 && p3.y >= rany1 && p3.y <= rany2) ||
				(p4.x >= ranx1 && p4.x <= ranx2 && p4.y >= rany1 && p4.y <= rany2) ||
				(p1.x >= ranx3 && p1.x <= ranx4 && p1.y >= rany3 && p1.y <= rany4) ||
				(p2.x >= ranx3 && p2.x <= ranx4 && p2.y >= rany3 && p2.y <= rany4);
		}
		else
		{
			if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) ||
				(p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) res = 1;
			else
				res = r1 != r2 && r3 != r4;
		}
	}
	else
		res = r1 != r2 && r3 != r4;
	cout << res << "\n";
	cout << fixed, cout.precision(9);

	if (res == 1)
	{
		bool sameD = 0;
		if (p1.x == p2.x && p3.x == p4.x) sameD = 1;
		else if (p1.x == p2.x)
		{
			dd d2 = (dd)(p3.y - p4.y) / (p3.x - p4.x);
			dd cx = (dd)p1.x;
			dd cy = (cx - p3.x) * d2 + p3.y;
			cout << cx << " " << cy << "\n";
		}
		else if (p3.x == p4.x)
		{
			dd d1 = (dd)(p1.y - p2.y) / (p1.x - p2.x);
			dd cx = (dd)p3.x;
			dd cy = (cx - p1.x) * d1 + p1.y;
			cout << cx << " " << cy << "\n";
		}
		else
		{
			dd d1 = (dd)(p1.y - p2.y) / (p1.x - p2.x);
			dd d2 = (dd)(p3.y - p4.y) / (p3.x - p4.x);
			if (d1 == d2) sameD = 1;
			else
			{
				dd cx = ((p1.y - p1.x * d1) - (p3.y - p3.x * d2)) / (d2 - d1);
				dd cy = (cx - p1.x) * d1 + p1.y;
				cout << cx << " " << cy << "\n";
			}
		}

		if (sameD)
		{
			ll cx, cy, otx1, oty1, otx2, oty2;
			bool pass = 0;
			if (p1.x == p3.x && p1.y == p3.y) {
				cx = p1.x, cy = p1.y, pass = 1;
				otx1 = p2.x, oty1 = p2.y, otx2 = p4.x, oty2 = p4.y;
			}
			if (p1.x == p4.x && p1.y == p4.y) {
				cx = p1.x, cy = p1.y, pass = 1;
				otx1 = p2.x, oty1 = p2.y, otx2 = p3.x, oty2 = p3.y;
			}
			if (p2.x == p3.x && p2.y == p3.y) {
				cx = p2.x, cy = p2.y, pass = 1;
				otx1 = p1.x, oty1 = p1.y, otx2 = p4.x, oty2 = p4.y;
			}
			if (p2.x == p4.x && p2.y == p4.y) {
				cx = p2.x, cy = p2.y, pass = 1;
				otx1 = p1.x, oty1 = p1.y, otx2 = p3.x, oty2 = p3.y;
			}

			if (pass)
			{
				if (p1.x == p2.x && p3.x == p4.x)
				{
					if (Sign(cy - oty1) != Sign(cy - oty2))
						cout << cx << " " << cy << "\n";
				}
				else
				{
					if (Sign(cx - otx1) != Sign(cx - otx2))
						cout << cx << " " << cy << "\n";
				}
			}
		}
	}
	return 0;
}
