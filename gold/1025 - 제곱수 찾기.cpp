#include <iostream>
#include <cmath>
using namespace std;

int N, M;
int board[11][11];
int answer = -1;

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
			board[y][x] = str[x] - 48;
	}

	for (int dx = -(M - 1); dx <= M - 1; dx++)
	{
		for (int dy = -(N - 1); dy <= N - 1; dy++)
		{
			for (int posx = 0; posx < M; posx++)
			{
				for (int posy = 0; posy < N; posy++)
				{
					int num = 0, scale = 1;
					int x = posx, y = posy;

					while (x >= 0 && x < M && y >= 0 && y < N)
					{
						num += board[y][x] * scale;
						scale *= 10;

						int sq = sqrt(num);
						if (sq * sq == num)
							answer = max(answer, num);

						y += dy;
						x += dx;
						if (dy == 0 && dx == 0) break;
					}
				}
			}
		}
	}

	cout << answer;
	return 0;
}