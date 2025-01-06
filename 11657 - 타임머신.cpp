#include <iostream>
#include <cmath>
using namespace std;
#define INF 9999999

class Edge {
public:
	int src, dest, weight;
	Edge(int a, int b, int c) { src = a, dest = b, weight = c; }
	Edge() {}
};

int V, E, S = 1;
long long dist[502];
Edge graph[6002];

bool BellmanFord()
{
	for (int v = 1; v <= V; v++)
		dist[v] = INF;
	dist[S] = 0;

	for (int i = 1; i <= V - 1; i++)
	{
		for (int e = 0; e < E; e++)
		{
			int src = graph[e].src;
			int dest = graph[e].dest;
			int weight = graph[e].weight;
			if (dist[src] != INF)
				dist[dest] = min(dist[dest], dist[src] + weight);
		}
	}

	// check negative-weight cycle
	for (int e = 0; e < E; e++)
	{
		int src = graph[e].src;
		int dest = graph[e].dest;
		int weight = graph[e].weight;
		if (dist[src] != INF && dist[dest] > dist[src] + weight)
			return false;
	}

	return true;
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[i] = Edge(a, b, w);
	}

	if (BellmanFord())
	{
		for (int i = 1; i <= V; i++)
		{
			if (i == S) continue;
			if (dist[i] != INF) printf("%lld\n", dist[i]);
			else printf("-1\n");
		}
	}
	else printf("-1\n");

	return 0;
}