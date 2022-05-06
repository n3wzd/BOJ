#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

typedef struct Point {
	ll x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	ll D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
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

	cout << res;
	return 0;
}
