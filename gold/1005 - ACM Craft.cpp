#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

int N, M, W;
vector<int> graph[1001];
int cooltime[1001];
int degree[1001];
int readytime[1001];

void TopologySort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if (degree[i] == 0)
			q.push(i);

	for (int i = 0; i < N; i++)
	{
		int v = q.front();
		q.pop();
		readytime[v] += cooltime[v];
		if (v == W) break;

		int len = graph[v].size();
		for (int k = 0; k < len; k++)
		{
			int w = graph[v][k];
			readytime[w] = max(readytime[w], readytime[v]);
			if (--degree[w] == 0)
				q.push(w);
		}
	}
	cout << readytime[W] << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; i++)
		{
			cin >> cooltime[i];
			graph[i].clear();
			readytime[i] = 0;
			degree[i] = 0;
		}

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			graph[a].push_back(b);
			degree[b]++;
		}
		cin >> W;

		TopologySort();
	}
	return 0;
}
