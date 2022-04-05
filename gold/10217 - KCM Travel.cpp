#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <utility>
using namespace std;
#define INF 99999999

class Edge {
public:
	int dest, cost, weight;
	Edge(int b, int c, int w) { dest = b, cost = c, weight = w; }
	Edge() {}
};

struct cmp {
	bool operator()(pair<int, int>& a, pair<int, int>& b) {
		return a.second > b.second;
	}
};

int N, M, K, S = 1;
int dist[102][10002];
bool visited[102] = { 0, };
vector<Edge> graph[10002];
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void DP()
{
	// Bottom-Up DP
	for (int money = 0; money <= M; money++)
	{
		// Dijkstra
		for (int i = 1; i <= N; i++)
		{
			dist[i][money] = INF;
			visited[i] = 0;
		}
		dist[S][money] = 0;
		pq.push(make_pair(S, 0));

		while (!pq.empty())
		{
			int src = pq.top().first;
			pq.pop();
			if (visited[src]) continue;
			visited[src] = 1;

			int len = graph[src].size();
			for (int i = 0; i < len; i++)
			{
				int dest = graph[src][i].dest;
				int cost = graph[src][i].cost;
				int weight = graph[src][i].weight;

				if (money - cost >= 0)
				{
					if (dist[dest][money] > dist[src][money - cost] + weight)
					{
						dist[dest][money] = dist[src][money - cost] + weight;
						pq.push(make_pair(dest, dist[dest][money]));
					}
				}
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		scanf("%d%d%d", &N, &M, &K);
		for (int i = 1; i <= K; i++)
		{
			int a, b, c, w;
			scanf("%d%d%d%d", &a, &b, &c, &w);
			graph[a].push_back(Edge(b, c, w));
		}

		DP();
		if(dist[N][M] != INF) cout << dist[N][M] << endl;
		else cout << "Poor KCM" << endl;

		for (int i = 1; i <= K; i++)
			graph[i].clear();
	}
	return 0;
}