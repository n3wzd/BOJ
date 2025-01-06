#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF 150000

struct cmp {
	bool operator()(pair<pair<int, int>, int>& a, pair<pair<int, int>, int>& b) {
		return a.second > b.second;
	}
};

int N;
int dist[130][130];
bool visited[130][130] = { 0, };
int cave[130][130];
priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0 ,-1 };

void Dijkstra(int sx, int sy)
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			dist[y][x] = INF;
			visited[y][x] = 0;
		}
	}
	dist[0][0] = cave[0][0];

	pq.push(make_pair(make_pair(0, 0), 0));
	while (!pq.empty())
	{
		pair<int, int> v = pq.top().first;
		int x = v.first, y = v.second;
		pq.pop();
		if (visited[y][x]) continue;
		visited[y][x] = 1;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < N && ny >= 0 && ny < N)
			{
				int w = cave[ny][nx];
				if (dist[y][x] + w < dist[ny][nx])
				{
					dist[ny][nx] = dist[y][x] + w;
					pq.push(make_pair(make_pair(nx, ny), dist[ny][nx]));
				}
			}
		}
	}
}

int main()
{
	int t = 1;
	while (1)
	{
		cin >> N;
		if (N == 0) break;

		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				scanf("%d", &cave[y][x]);

		Dijkstra(0, 0);
		cout << "Problem " << t << ": " << dist[N-1][N-1] << endl;
		t++;
	}
	
	return 0;
}