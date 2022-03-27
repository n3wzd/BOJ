#include <iostream>
#include <utility>
#include <queue>
using namespace std;
# define MAX_SIZE 1002

int N, M;
int min_dist[MAX_SIZE][MAX_SIZE] = { 0, }; // value: 0 - no visit, 1,2,3... - distance from start
int field[MAX_SIZE][MAX_SIZE] = { 0, };

int main()
{
	queue<pair<int, int>> q;
	cin >> M >> N;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			scanf("%d", &field[y][x]);
			if(field[y][x] == 1)
				q.push(make_pair(x, y));
		}
	}

	while (!q.empty())
	{
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx, ny;
			switch (i)
			{
			case 0: nx = x + 1, ny = y; break;
			case 1: nx = x - 1, ny = y; break;
			case 2: nx = x, ny = y + 1; break;
			case 3: nx = x, ny = y - 1; break;
			}

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if ((min_dist[ny][nx] == 0 || min_dist[ny][nx] > min_dist[y][x] + 1) && field[ny][nx] == 0)
				{
					q.push(make_pair(nx, ny));
					min_dist[ny][nx] = min_dist[y][x] + 1;
				}
			}
		}
	}

	int min_day = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (field[y][x] == 0 && min_dist[y][x] == 0)
			{
				cout << -1 << endl;
				return 0;
			}

			if (min_dist[y][x] > min_day)
				min_day = min_dist[y][x];
		}
	}
	cout << min_day << endl;
	return 0;
}