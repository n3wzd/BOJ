#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, V;
bool visited1[2000] = { 0, };
bool visited2[2000] = { 0, };
vector<int> graph[2000];

void DFS(int v)
{
	visited1[v] = true;
	printf("%d ", v);

	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i];
		if (!visited1[next])
		{
			DFS(next);
			visited1[next] = true;
		}
	}
}

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited2[s] = true;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		printf("%d ", v);

		int len = graph[v].size();
		for (int i = 0; i < len; i++)
		{
			int next = graph[v][i];
			if (!visited2[next])
			{
				q.push(next);
				visited2[next] = true;
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &N, &M, &V);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		if(graph[i].size() >= 1)
			sort(graph[i].begin(), graph[i].end());
	}

	DFS(V);
	printf("\n");
	BFS(V);
	return 0;
}