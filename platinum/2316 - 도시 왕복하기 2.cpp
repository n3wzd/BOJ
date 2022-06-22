#include <iostream>
#include <memory.h>
#define SIZE 805
using namespace std;
int N, M, maxFlow = 0;
int graph[SIZE][SIZE];
bool visited[SIZE];
const int S = 1, T = 2, INF = 1 << 29;

int DFS(int v, int flow, int goal) {
	visited[v] = 1;
	if (v == goal) return flow;

	for (int nv = 2; nv <= N * 2 + 1; nv++) {
		int w = graph[v][nv];
		if (visited[nv] || w == 0) continue;

		int nextFlow = DFS(nv, min(flow, w), goal);
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
	for (int v = 1; v <= N; v++)
		graph[v * 2][v * 2 + 1] = 1;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a * 2 + 1][b * 2] += 1;
		graph[b * 2 + 1][a * 2] += 1;
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		int flow = DFS(S * 2 + 1, INF, T * 2);
		if (flow == 0) break;
		maxFlow += flow;
	}
	cout << maxFlow;
	return 0;
}
