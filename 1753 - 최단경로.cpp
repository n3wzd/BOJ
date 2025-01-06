#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 9999999

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return (a.second == b.second) ? a.first > b.first : a.second > b.second;
	}
};

int V, W, S;
int dist[20002];
bool visited[20002] = { 0, };
vector<pair<int, int>> graph[20002];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

int main()
{
	scanf("%d%d%d", &V, &W, &S);
	for (int i = 1; i <= V; i++)
		dist[i] = INF;
	dist[S] = 0;

	for (int i = 1; i <= W; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(make_pair(b, w));
	}

	pq.push(make_pair(S, 0));
	while(!pq.empty())
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

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] != INF) printf("%d\n", dist[i]);
		else printf("INF\n");
	}
	
	return 0;
}