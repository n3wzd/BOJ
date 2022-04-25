#include <iostream>
#include <utility>
#include <queue>
using namespace std;
# define MAXV 100002

int N, K;
bool visited[MAXV] = { 0, };
int dist[MAXV] = { 0, };

void BFS(int start)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push(make_pair(0, start));
	dist[start] = 0;
	visited[start] = 1;

	while (!pq.empty())
	{
		int x = pq.top().second;
		pq.pop();

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
				if (!visited[nx])
				{
					dist[nx] = (i == 0) ? dist[x] : dist[x] + 1;
					pq.push(make_pair(dist[nx], nx));
					visited[nx] = 1;
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