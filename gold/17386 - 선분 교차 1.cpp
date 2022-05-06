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
	if (CCW(p1, p2, p3) == CCW(p1, p2, p4) || CCW(p3, p4, p1) == CCW(p3, p4, p2)) cout << 0;
	else cout << 1;
	return 0;
}
