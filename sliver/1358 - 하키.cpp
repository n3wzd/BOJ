#include <iostream>
#include <cmath>
using namespace std;

int W, H, X, Y, P, cnt = 0;
double R;

double Distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> W >> H >> X >> Y >> P;
	R = H / 2;
	for (int i = 0; i < P; i++)
	{
		int px, py;
		cin >> px >> py;

		bool ck = 0;
		if (Distance(px, py, X, Y + R) <= R) ck = 1;
		if (Distance(px, py, X + W, Y + R) <= R) ck = 1;
		if (px >= X && px <= X + W && py >= Y && py <= Y + H) ck = 1;
		if (ck) cnt++;
	}
	cout << cnt;
	return 0;
}
