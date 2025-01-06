#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF 99999999

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return (a.second == b.second) ? a.first > b.first : a.second > b.second;
	}
};

int N, E, B1, B2;
int dist[802];
bool visited[802] = { 0, };
vector<pair<int, int>> graph[802];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void Dijkstra(int S)
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[S] = 0;

	pq.push(make_pair(S, 0));
	while (!pq.empty())
	{
		int v = pq.top().first;
		pq.pop();
		if (visited[v]) continue;
		visited[v] = 1;

		int len = graph[v].size();
		for (int i = 0; i < len; i++)
		{
			int nv = graph[v][i].first;
			int w = graph[v][i].second;
			if (dist[v] + w < dist[nv])
			{
				dist[nv] = dist[v] + w;
				pq.push(make_pair(nv, dist[nv]));
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &E);
	for (int i = 1; i <= E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	scanf("%d%d", &B1, &B2);

	int final_dist[2] = { 0, 0 };
	int start[2][3] = { 1, B1, B2, 1, B2, B1 };
	int end[2][3] = { B1, B2, N, B2, B1, N };

	for (int j = 0; j < 2; j++)
	{
		for (int i = 0; i < 3; i++)
		{
			Dijkstra(start[j][i]);
			final_dist[j] += dist[end[j][i]];
		}
	}
	
	int min_final = min(final_dist[0], final_dist[1]);
	if (min_final >= INF) cout << -1 << endl;
	else cout << min_final << endl;
	return 0;
}