#include <iostream>
#include <cmath>
using namespace std;
#define INF 90000000

int V, E;
int adj[402][402];

void Floyd()
{
	for (int k = 1; k <= V; k++)
		for (int i = 1; i <= V; i++)
			for (int j = 1; j <= V; j++)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			adj[i][j] = INF;
	for (int v = 1; v <= V; v++)
		adj[v][v] = 0;

	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		adj[a][b] = min(adj[a][b], w);
	}
	Floyd();

	int cycle = INF;
	for (int i = 1; i <= V; i++)
		for (int j = i+1; j <= V; j++)
			cycle = min(cycle, adj[i][j] + adj[j][i]);

	if (cycle != INF) printf("%d\n", cycle);
	else printf("-1\n");

	return 0;
}