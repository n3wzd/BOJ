#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int cache[52][52];
int max_num = 0;

int Whirlpool(int x, int y)
{
	if (x == 0 && y == 0) return 1;

	int dire = 0;
	if (abs(x) > abs(y))
	{
		if (x > 0) dire = 3; // down
		if (x < 0) dire = 1; // up
	}
	else if (abs(x) < abs(y))
	{
		if (y > 0) dire = 0; // left
		if (y < 0) dire = 2; // right
	}
	else
	{
		if (x > 0 && y > 0) dire = 0;
		if (x < 0 && y < 0) dire = 2;
		if (x < 0 && y > 0) dire = 1;
		if (x > 0 && y < 0) dire = 3;
	}

	int n = max(abs(x), abs(y));
	int a;
	if (dire == 0) a = 8;
	if (dire == 1) a = 6;
	if (dire == 2) a = 4;
	if (dire == 3) a = 2;
	int num = n * (2 * a + 8 * (n - 1)) / 2 + 1;
	num -= (dire % 2 == 0) ? abs(y - x) : abs(y + x);
	return num;
}

int main()
{
	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	for (int y = r1; y <= r2; y++)
	{
		for (int x = c1; x <= c2; x++)
		{
			cache[y - r1][x - c1] = Whirlpool(x, y);
			max_num = max(max_num, cache[y - r1][x - c1]);
		}
	}

	int space = to_string(max_num).size();
	for (int y = r1; y <= r2; y++)
	{
		for (int x = c1; x <= c2; x++)
			printf("%*d", (x == c1) ? space : space + 1, cache[y - r1][x - c1]);
		printf("\n");
	}
	return 0;
}