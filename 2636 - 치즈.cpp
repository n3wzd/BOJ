#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M, after = 0, last_num = 0;
bool visited[105][105] = { 0, };
bool cheese[105][105] = { 0, };
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void BFS()
{
	queue<pair<int, int>> q;

	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!q.empty())
	{
		pair<int, int> v = q.front();
		int x = v.first, y = v.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx <= M+1 && ny >= 0 && ny <= N+1)
			{
				if (!visited[ny][nx])
				{
					visited[ny][nx] = 1;
					if (cheese[ny][nx] == 1) cheese[ny][nx] = 0;
					else q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= M; x++)
			scanf("%d", &cheese[y][x]);

	while (1)
	{
		int cheese_num = 0;
		for (int y = 0; y <= N+1; y++)
		{
			for (int x = 0; x <= M+1; x++)
			{
				if (cheese[y][x]) cheese_num++;
				visited[y][x] = 0;
			}
		}

		if (cheese_num > 0) BFS();
		else break;
		after++;
		last_num = cheese_num;
	}
	
	printf("%d\n%d\n", after, last_num);
	return 0;
}