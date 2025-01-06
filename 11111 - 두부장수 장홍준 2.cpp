#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 2505
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
struct Edge { int dest, weight, cap, prevIdx; };
int N, M, S, T;
ll dist[SIZE];
bool inQ[SIZE];
int trc_v[SIZE], trc_idx[SIZE];
vector<Edge> graph[SIZE];

int tofu[52][52];
const int RANK[5][5] = {
	10, 8, 7, 5, 1,
	8, 6, 4, 3, 1,
	7, 4, 3, 2, 1,
	5, 3, 2, 2, 1,
	1, 1, 1, 1, 0
};

bool SPFA() {
	memset(inQ, 0, sizeof(inQ));
	for (int i = 0; i < SIZE; i++) dist[i] = INF;
	queue <int> q;
	q.push(S), dist[S] = 0, inQ[S] = 1;

	while (!q.empty()) {
		int v = q.front(); q.pop();
		inQ[v] = 0;
		for (int i = 0; i < graph[v].size(); i++) {
			if (graph[v][i].cap == 0) continue;
			int nv = graph[v][i].dest, w = graph[v][i].weight;

			if (dist[nv] > dist[v] + w) {
				dist[nv] = dist[v] + w;
				trc_v[nv] = v, trc_idx[nv] = i;

				if (!inQ[nv]) {
					q.push(nv);
					inQ[nv] = 1;
				}
			}
		}
	}
	return dist[T] != INF;
}

void NetFlow() {
	int sumWeight = 0;
	while (SPFA()) {
		int minFlow = INF;
		for (int v = T; v != S; v = trc_v[v])
			minFlow = min(minFlow, graph[trc_v[v]][trc_idx[v]].cap);

		for (int v = T; v != S; v = trc_v[v]) {
			int pv = trc_v[v], pidx = trc_idx[v];
			graph[pv][pidx].cap -= minFlow;
			graph[v][graph[pv][pidx].prevIdx].cap += minFlow;
			sumWeight += minFlow * graph[pv][pidx].weight;
		}
	}
	cout << -sumWeight;
}

void MakeEdge(int a, int b, int w, int c) {
	graph[a].push_back({ b, w, c, (int)graph[b].size() });
	graph[b].push_back({ a, -w, 0, (int)graph[a].size() - 1 });
}

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
void Connect(int x, int y) {
	if ((y + x) % 2 != 0) return;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= M || ny < 0 || ny >= N) continue;
		MakeEdge(y * M + x, ny * M + nx, -RANK[tofu[y][x]][tofu[ny][nx]], 1);
	}
}

int Converter(char c) {
	switch (c) {
	case 'A': return 0;
	case 'B': return 1;
	case 'C': return 2;
	case 'D': return 3;
	case 'F': return 4;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	S = N * M, T = N * M + 1;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char c;
			cin >> c;
			tofu[y][x] = Converter(c);
			if ((y + x) % 2 == 0) MakeEdge(S, y * M + x, 0, 1);
			MakeEdge(y * M + x, T, 0, 1);
		}
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			Connect(x, y);

	NetFlow();
	return 0;
}
