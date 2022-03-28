#include <iostream>
#include <utility>
#include <queue>
using namespace std;
# define MAXV 100002

int N, K;
int dist[MAXV] = { 0, }; // value: 0 - no visit, 1,2,3... - distance from start

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == K) // destination
		{
			printf("%d\n", dist[x]);
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx;
			switch (i)
			{
			case 0: nx = x + 1; break;
			case 1: nx = x - 1; break;
			case 2: nx = x * 2; break;
			}

			if (nx >= 0 && nx < MAXV)
			{
				if (dist[nx] == 0)
				{
					q.push(nx);
					dist[nx] = dist[x] + 1;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	BFS(N);
	return 0;
}