#include <iostream>
using namespace std;

int N, M, pos_x, pos_y, dire, score = 0;
int stage[53][53];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

int main()
{
	cin >> N >> M >> pos_y >> pos_x >> dire;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &stage[y][x]);

	while (1)
	{
		if (stage[pos_y][pos_x] == 0)
		{
			score++;
			stage[pos_y][pos_x] = 2;
		}

		bool pass = 0;
		for (int i = 0; i < 4; i++)
		{
			dire = ((dire - 1) + 4) % 4;
			int nx = pos_x + dx[dire], ny = pos_y + dy[dire];
			if (stage[ny][nx] == 0)
			{
				pos_x = nx;
				pos_y = ny;
				pass = 1;
				break;
			}
		}

		if (!pass)
		{
			int nx = pos_x + dx[(dire + 2) % 4], ny = pos_y + dy[(dire + 2) % 4];
			if (stage[ny][nx] != 1)
			{
				pos_x = nx;
				pos_y = ny;
				continue;
			}
			break;
		}
	}

	printf("%d\n", score);
	return 0;
}