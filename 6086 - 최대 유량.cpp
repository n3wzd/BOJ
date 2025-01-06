#include <iostream>
#include <memory.h>
#define SIZE 55
using namespace std;
int M, maxFlow = 0;
int graph[SIZE][SIZE];
bool visited[SIZE];
const int S = 0, T = 25, INF = 1 << 29;

int DFS(int v, int flow) {
	visited[v] = 1;
	if (v == T) return flow;

	for (int nv = 0; nv < SIZE; nv++) {
		int w = graph[v][nv];
		if (visited[nv] || w == 0) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][nv] -= nextFlow;
			graph[nv][v] += nextFlow;
			return nextFlow;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M;
	for (int i = 0; i < M; i++) {
		char ca, cb;
		int a, b, w;
		cin >> ca >> cb >> w;
		a = (ca < 'a') ? ca - 'A' : ca - 'a' + 26;
		b = (cb < 'a') ? cb - 'A' : cb - 'a' + 26;
		graph[a][b] += w;
		graph[b][a] += w;
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		int flow = DFS(S, INF);
		if (flow == 0) break;
		maxFlow += flow;
	}
	cout << maxFlow;
	return 0;
}
