#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 505
using namespace std;
typedef long long ll;
const int INF = (1 << 30) - 1;
struct Edge { int dest, weight, cap, prevIdx; };
int Q, N, M, S, T;
ll dist[SIZE];
bool inQ[SIZE];
int trc_v[SIZE], trc_idx[SIZE];
vector<Edge> graph[SIZE];
bool color[SIZE];

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
	cout << sumWeight << "\n";
}

void MakeEdge(int a, int b, int w, int c) {
	graph[a].push_back({ b, w, c, (int)graph[b].size() });
	graph[b].push_back({ a, -w, 0, (int)graph[a].size() - 1 });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) {
		cin >> N >> M;
		S = 0, T = N + 1;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			MakeEdge(a, b, 1, INF);
			MakeEdge(b, a, 1, INF);
		}
		for (int i = 1; i <= N; i++) cin >> color[i];
		for (int i = 1; i <= N; i++) {
			bool coin;
			cin >> coin;
			if (coin != color[i]) {
				if(color[i]) MakeEdge(S, i, 0, 1);
				else MakeEdge(i, T, 0, 1);
			}
		}
		NetFlow();

		for (int i = 0; i < SIZE; i++)
			graph[i].clear();
	}
	return 0;
}
