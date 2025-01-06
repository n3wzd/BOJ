#include <iostream>
#include <cmath>
using namespace std;
#define INF 90000000

int V;
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
	scanf("%d", &V);
	for (int i = 1; i <= V; i++)
		for (int j = 1; j <= V; j++)
			adj[i][j] = INF;

	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			int w;
			scanf("%d", &w);
			if(w == 1) adj[i][j] = 1;
		}
	}

	Floyd();
	for (int i = 1; i <= V; i++)
	{
		for (int j = 1; j <= V; j++)
		{
			if (adj[i][j] != INF) printf("1 ");
			else printf("0 ");
		}
		printf("\n");
	}

	return 0;
}