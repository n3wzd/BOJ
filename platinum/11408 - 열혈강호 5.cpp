#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 805
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
struct Edge { int dest, weight, cap, prevIdx; };
int N, M, S = 1, T;
ll dist[SIZE];
bool inQ[SIZE];
int trc_v[SIZE], trc_idx[SIZE];
vector<Edge> graph[SIZE];

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
	int sumFlow = 0, sumWeight = 0;
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
		sumFlow += minFlow;
	}
	cout << sumFlow << "\n" << sumWeight << "\n";
}

void MakeEdge(int a, int b, int w, int c) {
	graph[a].push_back({ b, w, c, (int)graph[b].size() });
	graph[b].push_back({ a, -w, 0, (int)graph[a].size() - 1 });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	S = N + M, T = N + M + 1;
	for (int n = 0; n < N; n++) {
		int len, work, cost;
		cin >> len;
		while (len--) {
			cin >> work >> cost;
			MakeEdge(n, N + work - 1, cost, 1);
		}
		MakeEdge(S, n, 0, 1);
	}
	for (int m = 0; m < M; m++)
		MakeEdge(N + m, T, 0, 1);

	NetFlow();
	return 0;
}
