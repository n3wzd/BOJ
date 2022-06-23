#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 105
using namespace std;
int N, sumAll = 0;
int graph[SIZE][SIZE];
int level[SIZE], work[SIZE];
int row[52], col[52];
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

bool Pass(int cap) {
	for (int r = 1; r <= N; r++) graph[S][r] = row[r], graph[r][S] = 0;
	for (int c = 1; c <= N; c++) graph[N + c][T] = col[c], graph[T][N + c] = 0;
	for (int r = 1; r <= N; r++)
		for (int c = 1; c <= N; c++)
			graph[r][N + c] = cap, graph[N + c][r] = 0;
	return (sumAll == NetFlow());
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> row[i], sumAll += row[i];
	for (int i = 1; i <= N; i++) cin >> col[i];
	S = 0, T = N * 2 + 1;
	
	int start = 0, end = 10000, mid;
	while (end - start >= 0) {
		mid = (start + end) / 2;
		if (Pass(mid)) end = mid - 1;
		else start = mid + 1;
	}
	
	Pass(start);
	cout << start << "\n";
	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= N; c++)
			cout << graph[N + c][r] << " ";
		cout << "\n";
	}
	return 0;
}
