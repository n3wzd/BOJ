#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
vector<int> graph[10001];
int parent[10001];
int depth[10001];
bool root_not[10001];

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
	int T;
	cin >> T;
	while (T--) {
		cin >> N;
		memset(parent, 0, sizeof(parent));
		memset(depth, 0, sizeof(depth));
		memset(root_not, 0, sizeof(root_not));
		for (int i = 0; i <= N; i++)
			graph[i].clear();

		for (int i = 0; i < N - 1; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			root_not[b] = 1;
		}

		int root = 1;
		for (int i = 1; i <= N; i++)
			if (!root_not[i])
				root = i;
		DFS(root, 1);

		int n1, n2;
		cin >> n1 >> n2;
		cout << LCA(n1, n2) << "\n";
	}
	return 0;
}