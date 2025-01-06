#include <iostream>
#include <cmath>
using namespace std;
#define INF 90000000

int V, E, S = 1;
int adj[102][102];

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
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if(adj[i][j] != INF) printf("%d ", adj[i][j]);
			else printf("0 ", adj[i][j]);
		}
		printf("\n");
	}

	return 0;
}