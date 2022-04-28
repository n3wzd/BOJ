#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
bool visited[100002];
int parent[100002];
vector<int> graph[100002];

void DFS(int v)
{
	visited[v] = true;

	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i];
		if (!visited[next])
		{
			parent[next] = v;
			DFS(next);
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1);
	for (int i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
	return 0;
}