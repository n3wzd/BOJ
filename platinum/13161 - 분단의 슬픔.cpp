#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 505
using namespace std;
int N, sadSum = 0;
int graph[SIZE][SIZE];
int level[SIZE], work[SIZE];
int team[SIZE];
bool visited[SIZE];
int S, T, INF = 1 << 29;

bool BFS() {
	memset(level, -1, sizeof(level));
	queue <int> q;
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int nv = 0; nv < SIZE; nv++) {
			int w = graph[v][nv];
			if (level[nv] != -1 || w == 0) continue;

			level[nv] = level[v] + 1;
			q.push(nv);
		}
	}
	return level[T] != -1;
}

int DFS(int v, int flow) {
	if (v == T) return flow;

	for (int& nv = work[v]; nv < SIZE; nv++) {
		int w = graph[v][nv];
		if (w == 0 || level[v] + 1 != level[nv]) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][nv] -= nextFlow;
			graph[nv][v] += nextFlow;
			return nextFlow;
		}
	}
	return 0;
}

int NetFlow() {
	int sumFlow = 0;
	while (BFS()) {
		memset(work, 0, sizeof(work));
		while (1) {
			int flow = DFS(S, INF);
			if (flow == 0) break;
			sumFlow += flow;
		}
	}
	return sumFlow;
}

void DFS2(int v) {
	team[v] = 1;
	visited[v] = 1;
	if (v == T) return;

	for (int nv = 0; nv < SIZE; nv++) {
		if (graph[v][nv] == 0 || visited[nv]) continue;
		DFS2(nv);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	S = 0, T = N + 1;
	for (int v = 1; v <= N; v++) {
		cin >> team[v];
		if (team[v] == 1) graph[S][v] = INF;
		if (team[v] == 2) graph[v][T] = INF;
	}
	for (int v = 1; v <= N; v++) {
		for (int nv = 1; nv <= N; nv++) {
			int sad;
			cin >> sad;
			graph[v][nv] = sad;
		}
	}

	cout << sadSum + NetFlow() << "\n";
	DFS2(S);
	for (int t = 1; t >= 0; t--) {
		for (int v = 1; v <= N; v++)
			if (team[v] % 2 == t)
				cout << v << " ";
		cout << "\n";
	}
	return 0;
}
