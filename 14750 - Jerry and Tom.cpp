#include <iostream>
#include <queue>
#include <memory.h>
#define SIZE 305
using namespace std;
typedef long long ll;
struct Edge { int next, cap, prevIdx; };
int N, K, H, M;
vector<Edge> graph[SIZE];
int level[SIZE], work[SIZE];
int S, T, INF = 1 << 29;

typedef struct Point { int x, y; } Point;
typedef struct Line { Point p1, p2; } Line;
Line home[1002];
Point hole[52];

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

bool PointEqual(Point p1, Point p2) {
	return (p1.x == p2.x) && (p1.y == p2.y);
}

int CCW(Point a, Point b, Point c) {
	ll D = ((ll)b.x - a.x) * ((ll)c.y - a.y) - ((ll)c.x - a.x) * ((ll)b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

bool Intersect(Point p1, Point p2, Point p3, Point p4) {
	int r1 = CCW(p1, p2, p3), r2 = CCW(p1, p2, p4);
	int r3 = CCW(p3, p4, p1), r4 = CCW(p3, p4, p2);
	bool res;

	if (r1 == 0 || r2 == 0 || r3 == 0 || r4 == 0) {
		if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0) {
			int ranx1 = min(p1.x, p2.x), ranx2 = max(p1.x, p2.x);
			int rany1 = min(p1.y, p2.y), rany2 = max(p1.y, p2.y);
			int ranx3 = min(p3.x, p4.x), ranx4 = max(p3.x, p4.x);
			int rany3 = min(p3.y, p4.y), rany4 = max(p3.y, p4.y);
			res = (p3.x >= ranx1 && p3.x <= ranx2 && p3.y >= rany1 && p3.y <= rany2) ||
				(p4.x >= ranx1 && p4.x <= ranx2 && p4.y >= rany1 && p4.y <= rany2) ||
				(p1.x >= ranx3 && p1.x <= ranx4 && p1.y >= rany3 && p1.y <= rany4) ||
				(p2.x >= ranx3 && p2.x <= ranx4 && p2.y >= rany3 && p2.y <= rany4);
		}
		else {
			if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) ||
				(p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) res = 1;
			else res = r1 != r2 && r3 != r4;
		}
	}
	else res = r1 != r2 && r3 != r4;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> H >> M;
	S = M + H, T = M + H + 1;
	Point p1, p2, p0;
	cin >> p1.x >> p1.y;
	p0 = p1;
	for (int i = 0; i < N - 1; i++) {
		cin >> p2.x >> p2.y;
		home[i] = { p1, p2 };
		p1 = p2;
	}
	home[N - 1] = { p2, p0 };

	for (int h = 0; h < H; h++) {
		cin >> hole[h].x >> hole[h].y;
		MakeEdge(M + h, T, K);
	}
	for (int m = 0; m < M; m++) {
		Point mouse;
		cin >> mouse.x >> mouse.y;
		MakeEdge(S, m, 1);
		for (int h = 0; h < H; h++) {
			int crs = 0;
			for (int i = 0; i < N; i++)
				if (!(PointEqual(hole[h], home[i].p1) || PointEqual(hole[h], home[i].p2)))
					if (Intersect(mouse, hole[h], home[i].p1, home[i].p2))
						crs++;
			if (crs <= 1)
				MakeEdge(m, M + h, 1);
		}
	}

	if (M == NetFlow()) cout << "Possible";
	else cout << "Impossible";
	return 0;
}
