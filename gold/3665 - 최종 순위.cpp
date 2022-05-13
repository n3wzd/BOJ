#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

const int _SIZE = 501;
int N, M;
int degree[_SIZE], order[_SIZE];
int ptot[_SIZE], ttop[_SIZE];
bool graph[_SIZE][_SIZE];

void TopologySort()
{
	queue<int> q;
	for (int i = 1; i <= N; i++)
		if(degree[i] == 0)
			q.push(i);

	for (int i = 0; i < N; i++)
	{
		if (q.empty()) {
			cout << "IMPOSSIBLE" << "\n";
			return;
		}
		int v = q.front();
		q.pop();
		order[i] = v;

		for (int w = 1; w <= N; w++)
		{
			if(graph[v][w])
				if (--degree[w] == 0)
					q.push(w);
		}
	}

	for (int i = 0; i < N; i++)
		cout << order[i] << " ";
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		memset(degree, 0, sizeof(int) * (N+1));
		for (int i = 0; i <= N; i++)
			memset(graph[i], 0, sizeof(bool) * (N+1));

		for (int i = 0; i < N; i++) {
			cin >> ptot[i];
			ttop[ptot[i]] = i;
		}
		
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				graph[ptot[i]][ptot[j]] = 1;
				degree[ptot[j]]++;
			}
		}

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			int a, b; // previous priority: a < b (a -> b)
			cin >> a >> b;
			if (ttop[a] > ttop[b]) {
				int temp = a;
				a = b;
				b = temp;
			}

			graph[a][b] = 0, graph[b][a] = 1;
			degree[a]++, degree[b]--;
		}
		TopologySort();
	}
	return 0;
}
