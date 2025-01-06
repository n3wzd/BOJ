#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
bool visited[502];
vector<int> graph[502];
bool isTree;

void DFS(int v, int prev)
{
	visited[v] = true;
	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i];
		if (!visited[next]) DFS(next, v);
		else if(next != prev) isTree = 0;
	}
}

int main()
{
	int T = 1;
	while (1)
	{
		scanf("%d%d", &N, &M);
		if (N == 0 && M == 0) return 0;
		for (int i = 1; i <= N; i++)
			graph[i].clear();

		for (int i = 1; i <= M; i++)
		{
			int v, w;
			scanf("%d%d", &v, &w);
			graph[v].push_back(w);
			graph[w].push_back(v);
		}

		int treeNum = 0;
		memset(visited, 0, N + 1);
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
			{
				isTree = 1;
				DFS(i, 0);
				if (isTree) treeNum++;
			}
		}
		
		printf("Case %d: ", T);
		if (treeNum == 0) printf("No trees.\n");
		else if (treeNum == 1) printf("There is one tree.\n");
		else printf("A forest of %d trees.\n", treeNum);
		T++;
	}
}