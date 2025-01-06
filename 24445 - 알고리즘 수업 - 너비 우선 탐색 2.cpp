#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define SIZE 100001
using namespace std;

int N, M, V, order = 1;
int visited[SIZE];
vector<int> graph[SIZE];

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = order++;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		int len = graph[v].size();
		for (int i = 0; i < len; i++)
		{
			int next = graph[v][i];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = order++;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end(), greater<int>());

	BFS(V);
	for (int i = 1; i <= N; i++)
		cout << visited[i] << "\n";

	return 0;
}