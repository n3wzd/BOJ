#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 2505
using namespace std;
struct Edge { int next, cap, prevIdx; };
int Q, N, M;
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

void MakeEdge(int a, int b, int w) {
	graph[a].push_back({ b, w, (int)graph[b].size() });
	graph[b].push_back({ a, 0, (int)graph[a].size() - 1 });
}

void Init() {
	memset(level, 0, sizeof(level));
	memset(work, 0, sizeof(work));
	for (int i = 0; i < SIZE; i++)
		graph[i].clear();
}

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void Connect(int x, int y) {
	if ((y + x) % 2 != 0) return;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		MakeEdge(y * M + x, ny * M + nx, INF);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) {
		Init();
		cin >> N >> M;
		S = N * M, T = N * M + 1;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				int num;
				cin >> num;
				if ((y + x) % 2 == 0) MakeEdge(S, y * M + x, num);
				else MakeEdge(y * M + x, T, num);
			}
		}
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				Connect(x, y);

		int sum = NetFlow();
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if ((y + x) % 2 != 0)
					sum += graph[y * M + x][0].cap;

		int len = graph[S].size();
		for (int i = 0; i < len; i++)
			sum += graph[S][i].cap;
		
		cout << sum << "\n";
	}
	return 0;
}
