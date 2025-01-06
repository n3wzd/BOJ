#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
vector<int> graph[100001];
int parent[100001][18];
int depth[100001];
int max_depth;

void DFS(int v, int d)
{
	depth[v] = d;
	for (int k = 1; k <= max_depth; k++)
		parent[v][k] = parent[parent[v][k-1]][k-1];

	for (int i = 0; i < graph[v].size(); i++)
	{
		int next = graph[v][i];
		if (depth[next] == 0)
		{
			parent[next][0] = v;
			DFS(next, d + 1);
		}
	}
}

int LCA(int n1, int n2)
{
	if (depth[n1] > depth[n2]) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	if(depth[n1] != depth[n2])
		for (int k = max_depth; k >= 0; k--)
			if (depth[n1] <= depth[parent[n2][k]])
				n2 = parent[n2][k];

	if (n1 == n2) return n1;
	for (int k = max_depth; k >= 0; k--)
	{
		if (parent[n1][k] != parent[n2][k])
		{
			n1 = parent[n1][k];
			n2 = parent[n2][k];
		}
	}
	return parent[n1][0];
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
	max_depth = (int)floor(log2(100001));
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
