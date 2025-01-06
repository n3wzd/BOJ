#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int _SIZE = 32001;
int N, M;
int degree[_SIZE];
vector<int> graph[_SIZE];

void TopologySort()
{
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 1; i <= N; i++)
		if(degree[i] == 0)
			q.push(i);

	for (int i = 0; i < N; i++)
	{
		int v = q.top();
		q.pop();
		cout << v << " ";

		int len = graph[v].size();
		for (int k = 0; k < len; k++)
		{
			int w = graph[v][k];
			if (--degree[w] == 0)
				q.push(w);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		degree[b]++;
	}
	TopologySort();
	return 0;
}
