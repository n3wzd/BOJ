#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Vector2 {
public:
	int x, y;
	Vector2(int a, int b) { x = a, y = b; }
	Vector2() { x = 0, y = 0; }
	void Add(Vector2 v) { x += v.x, y += v.y; }
	void Sub(Vector2 v) { x -= v.x, y -= v.y; }
};

Vector2 vec[22];
int N;
bool state[22];
double res = -1;

void C(int index, int start)
{
	if (index == N / 2)
	{
		Vector2 v;
		for (int i = 0; i < N; i++)
			(state[i]) ? v.Add(vec[i]) : v.Sub(vec[i]);
		double dist = sqrt((double)v.x * v.x + (double)v.y * v.y);
		if (dist < res || res == -1) res = dist;
		return;
	}

	for (int i = start; i < N; i++)
	{
		state[i] = 1;
		C(index + 1, i + 1);
		state[i] = 0;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			vec[i] = Vector2(x, y);
		}
		res = -1;

		C(0, 0);
		printf("%.12f\n", res);
	}
	return 0;
}