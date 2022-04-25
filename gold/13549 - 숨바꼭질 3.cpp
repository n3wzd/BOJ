#include <iostream>
#include <queue>
using namespace std;
# define MAXV 100002

int N, K;
int dist[MAXV] = { 0, };

void BFS(int start)
{
	for (int i = 0; i < MAXV; i++)
		dist[i] = MAXV;

	deque<int> deq;
	deq.push_back(start);
	dist[start] = 0;

	while (!deq.empty())
	{
		int x = deq.front();
		deq.pop_front();

		if (x == K) // destination
		{
			printf("%d\n", dist[x]);
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx;
			if (i == 0) nx = x * 2;
			if (i == 1) nx = x + 1;
			if (i == 2) nx = x - 1;

			if (nx >= 0 && nx < MAXV)
			{
				if (i == 0 && dist[nx] > dist[x])
				{
					dist[nx] = dist[x];
					deq.push_front(nx);
				}
				else if (dist[nx] > dist[x] + 1)
				{
					dist[nx] = dist[x] + 1;
					deq.push_back(nx);
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