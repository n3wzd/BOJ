#include <iostream>
#include <utility>
#include <queue>
using namespace std;
# define MAX_SIZE 102

int N, M;
int dist[MAX_SIZE][MAX_SIZE] = { 0, }; // value: 0 - no visit, 1,2,3... - distance from start
bool field[MAX_SIZE][MAX_SIZE] = { 0, };

void BFS(int sx, int sy)
{
	queue<pair<int, int>> q;

	q.push(make_pair(sx, sy));
	dist[sy][sx] = 1;

	while (!q.empty())
	{
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();

		if (x == M - 1 && y == N - 1) // destination
		{
			printf("%d\n", dist[y][x]);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx, ny;
			switch (i)
			{
			case 0: nx = x+1, ny = y; break;
			case 1: nx = x-1, ny = y; break;
			case 2: nx = x, ny = y+1; break;
			case 3: nx = x, ny = y-1; break;
			}

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (dist[ny][nx] == 0 && field[ny][nx])
				{
					q.push(make_pair(nx, ny));
					dist[ny][nx] = dist[y][x] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string s;
		cin >> s;
		for (int x = 0; x < M; x++)
			field[y][x] = s[x] - 48;
	}

	BFS(0, 0);
	return 0;
}