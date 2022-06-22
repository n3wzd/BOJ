#include <iostream>
#include <memory.h>
#define SIZE 402
using namespace std;
int N, M, maxFlow = 0;
int graph[SIZE][SIZE];
bool visited[SIZE];
const int S = 1, T = 2, INF = 1 << 29;

int DFS(int v, int flow) {
	visited[v] = 1;
	if (v == T) return flow;

	for (int nv = 1; nv <= N; nv++) {
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
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] += 1;
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
