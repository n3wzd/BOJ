#include <iostream>
using namespace std;

char board[50][50];

int Scan(int posX, int posY, bool checker)
{
	int paint = 0;
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			char pos = board[y + posY][x + posX];
			if (checker && pos == 'B') paint += 1;
			if (!checker && pos == 'W') paint += 1;
			checker = !checker;
		}
		checker = !checker;
	}
	return paint;
}

int main()
{
	int n, m, min = 2500;
	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> board[y][x];

	for (int dy = 0; dy <= n - 8; dy++)
	{
		for (int dx = 0; dx <= m - 8; dx++)
		{
			int paint1 = Scan(dx, dy, true);
			int paint2 = Scan(dx, dy, false);
			int paint_min = (paint1 < paint2) ? paint1 : paint2;
			if (min > paint_min) min = paint_min;
		}
	}

	cout << min << endl;
	return 0;
}