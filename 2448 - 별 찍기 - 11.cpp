#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point(int a, int b) { x = a, y = b; }
};

int N;
bool map[10000][10000] = { 0, };

void Triforce(Point p, int n)
{
	if (n == 3)
	{
		for (int dy = 0; dy < 3; dy++)
			for (int dx = -dy; dx <= dy; dx++)
				map[p.y + dy][p.x + dx] = 1;
		map[p.y + 1][p.x] = 0;
		return;
	}

	Triforce(p, n / 2);
	Triforce(Point(p.x - n / 2, p.y + n / 2), n / 2);
	Triforce(Point(p.x + n / 2, p.y + n / 2), n / 2);
}

void Print()
{
	for (int y = 1; y <= N; y++)
	{
		for (int x = 1; x <= N * 2 - 1; x++)
		{
			if (map[y][x]) printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}

int main()
{
	cin >> N;
	Triforce(Point(N, 1), N);
	Print();
	return 0;
}