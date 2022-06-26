#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#define SIZE 2005
using namespace std;
struct Edge { int next, cap, prevIdx; };
int N, M, F;
vector<Edge> graph[SIZE];
bool visited[SIZE];
int parent[SIZE];
int level[SIZE], work[SIZE];
int S, S2, T, INF = 1 << 29;

bool BFS() {
	memset(level, -1, sizeof(level));
	queue <int> q;
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		int len = graph[v].size();
		for (int i = 0; i < len; i++) {
			int w = graph[v][i].cap, nv = graph[v][i].next;
			if (level[nv] != -1 || w == 0) continue;
			level[nv] = level[v] + 1;
			q.push(nv);
		}
	}
	return level[T] != -1;
}

int DFS(int v, int flow) {
	if (v == T) return flow;

	int len = graph[v].size();
	for (int& i = work[v]; i < len; i++) {
		int w = graph[v][i].cap, nv = graph[v][i].next, prev = graph[v][i].prevIdx;
		if (w == 0 || level[v] + 1 != level[nv]) continue;

		int nextFlow = DFS(nv, min(flow, w));
		if (nextFlow) {
			graph[v][i].cap -= nextFlow;
			graph[nv][prev].cap += nextFlow;
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

void MakeEdge(int a, int b, int w) {
	graph[a].push_back({ b, w, (int)graph[b].size() });
	graph[b].push_back({ a, 0, (int)graph[a].size() - 1 });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> F;
	S = N + M, S2 = N + M + 1, T = N + M + 2;
	MakeEdge(S, S2, F);
	for (int n = 0; n < N; n++) {
		int len, work;
		cin >> len;
		MakeEdge(S, n, 1);
		MakeEdge(S2, n, len);
		while (len--) {
			cin >> work;
			MakeEdge(n, N + work - 1, 1);
		}
	}
	for (int m = 0; m < M; m++)
		MakeEdge(N + m, T, 1);
	cout << NetFlow();
	return 0;
}
