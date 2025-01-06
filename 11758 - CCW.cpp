#include <iostream>
using namespace std;

typedef struct Point {
	int x, y;
} Point;

int CCW(Point a, Point b, Point c)
{
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	Point a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	cout << CCW(a, b, c);
	return 0;
}
