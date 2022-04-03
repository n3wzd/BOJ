#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
#define INF 999999999

class Node {
public:
	int v, d;
	Node(int a, int b, int c) { v = a, d = b; }
};

struct cmp {
	bool operator()(Node& a, Node& b) {
		return (a.d == b.d) ? a.v > b.v : a.d > b.d;
	}
};

int N, M, T, S, G, H;
int dest[102];
vector<int> final_dest;
int dist2[3][2002];
int GH_dist;

int dist[2002];
bool visited[2002] = { 0, };
vector<pair<int, int>> graph[2002];
priority_queue<Node, vector<Node>, cmp> pq;

void Dijkstra(int S)
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[S] = 0;

	pq.push(Node(S, 0, 0));
	while (!pq.empty())
	{
		Node node = pq.top();
		int v = node.v;
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
				pq.push(Node(nv, dist[nv], v));
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d%d%d%d%d", &N, &M, &T, &S, &G, &H);
		for (int i = 1; i <= N; i++)
			graph[i].clear();

		for (int i = 1; i <= M; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			graph[a].push_back(make_pair(b, w));
			graph[b].push_back(make_pair(a, w));

			if ((a == G && b == H) || (a == H && b == G)) GH_dist = w;
		}
		for (int i = 1; i <= T; i++)
			scanf("%d", &dest[i]);
		final_dest.clear();

		Dijkstra(S);
		for (int i = 1; i <= N; i++)
			dist2[0][i] = dist[i];
		Dijkstra(H);
		for (int i = 1; i <= N; i++)
			dist2[1][i] = dist2[0][G] + GH_dist + dist[i];
		Dijkstra(G);
		for (int i = 1; i <= N; i++)
			dist2[2][i] = dist2[0][H] + GH_dist + dist[i];

		for (int i = 1; i <= T; i++)
		{
			int d = dest[i];
			if (dist2[0][d] == dist2[1][d] || dist2[0][d] == dist2[2][d])
				final_dest.push_back(d);
		}
		sort(final_dest.begin(), final_dest.end());

		int len = final_dest.size();
		for (int i = 0; i < len; i++)
			printf("%d ", final_dest[i]);
		printf("\n");
	}
	return 0;
}