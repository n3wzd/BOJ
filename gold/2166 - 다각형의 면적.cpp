#include <iostream>
#include <cmath>
using namespace std;

typedef struct Point {
	long long x, y;
} Point;

int N;
long long area1 = 0, area2 = 0;
Point p[10002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> p[i].x >> p[i].y;
	p[N] = p[0];

	for (int i = 0; i < N; i++)
	{
		area1 += p[i].x * p[i + 1].y;
		area2 += p[i].y * p[i + 1].x;
	}
	
	cout << fixed, cout.precision(1);
	cout << round((double)abs(area1 - area2) / 2 * 10) / 10;
	return 0;
}