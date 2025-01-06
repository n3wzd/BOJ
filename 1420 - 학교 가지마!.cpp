#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 20002
using namespace std;
struct Edge { int next, cap, prevIdx; };
int N, M;
vector<Edge> graph[SIZE];
int level[SIZE], work[SIZE];
int S, T, INF = 1 << 29;

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

int In(int a) {	return a * 2; }
int Out(int a) { return a * 2 + 1; }

void MakeEdge(int a, int b, int w) {
	graph[a].push_back({ b, w, (int)graph[b].size() });
	graph[b].push_back({ a, 0, (int)graph[a].size() - 1 });
}

void Connect(int id) {
	int dx[4] = { 1, M, -1, -M };
	for (int d = 0; d < 4; d++) {
		int newId = id + dx[d];
		if (newId < 0 || newId >= N * M) continue;
		if (d % 2 == 0 && id / M != newId / M) continue;
		MakeEdge(Out(id), In(newId), 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int id = y * M + x;
			char c;
			cin >> c;
			if (c == 'K') S = id;
			if (c == 'H') T = id;
			if (c != '#') MakeEdge(In(id), Out(id), 1);
			Connect(id);
		}
	}

	if ((S / M == T / M && S + 1 == T) || (S / M == T / M && S - 1 == T)
		|| S + M == T || S - M == T) cout << "-1";
	else {
		S = Out(S), T = In(T);
		cout << NetFlow();
	}
	return 0;
}
