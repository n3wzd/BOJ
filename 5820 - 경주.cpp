#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 200002, INF = 200002;
struct Edge { int v, w; };
struct Path { int dist, depth; };
int N, K, race = INF, sz[SIZE], course[1000002];
vector<Edge> con[SIZE];
vector<int> used_dist;
vector<Path> path;
bool visited[SIZE];

int SetSize(int v, int prev, int d) {
	sz[v] = 1;
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i])
			sz[v] += SetSize(i, v, d + 1);
	}
	return sz[v];
}

int Centroid(int v, int prev, int size) {
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i] && sz[i] * 2 > size)
			return Centroid(i, v, size);
	}	
	return v;
}

void Race(int v, int prev, int depth, int dist) {
	if (dist > K)
		return;

	race = min(race, depth + course[K - dist]);
	path.push_back({dist, depth});
	used_dist.push_back(dist);
	
	for (auto next : con[v]) {
		int i = next.v;
		if (i != prev && !visited[i])
			Race(i, v, depth + 1, dist + next.w);
	}
}

void DC(int root) {
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	for (auto i : used_dist)
		course[i] = INF;
	used_dist.clear();
	for (auto next : con[ctr]) {
		int i = next.v;
		if (!visited[i])
			Race(i, ctr, 1, next.w);

		for (auto p : path)
			course[p.dist] = min(course[p.dist], p.depth);
		path.clear();
	}

	for (auto next : con[ctr]) {
		int i = next.v;
		if (!visited[i])
			DC(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		con[a].push_back({b, w});
		con[b].push_back({a, w});
	}
	for (int i = 1; i <= K; i++)
		course[i] = INF;

	DC(0);
	cout << (race != INF ? race : -1);
	return 0;
}
