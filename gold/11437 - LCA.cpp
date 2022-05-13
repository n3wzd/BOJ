#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> graph[50001];
int parent[50001];
int depth[50001];

void DFS(int v, int d)
{
	depth[v] = d;
	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (depth[next] == 0)
		{
			parent[next] = v;
			DFS(next, d + 1);
		}
	}
}

int LCA(int n1, int n2)
{
	while (depth[n1] > depth[n2]) n1 = parent[n1];
	while (depth[n1] < depth[n2]) n2 = parent[n2];

	while (n1 != n2)
	{
		n1 = parent[n1];
		n2 = parent[n2];
	}
	return n1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		cout << LCA(n1, n2) << "\n";
	}
	return 0;
}
