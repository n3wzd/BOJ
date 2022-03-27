#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool visited[102] = { 0, };
vector<int> graph[102];
int virus = 0;

void DFS(int v)
{
	visited[v] = true;
	virus++;

	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i];
		if (!visited[next])
		{
			DFS(next);
			visited[next] = true;
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	DFS(1);
	cout << virus-1 << endl;
	return 0;
}