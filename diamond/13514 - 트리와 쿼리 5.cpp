#include <iostream>
#include <vector>
#include <set>
using namespace std;
const int SIZE = 100002;
int N, M, sz[SIZE], parent_ctr[SIZE];
vector<int> con[SIZE];
bool visited[SIZE], color[SIZE];
multiset<int> whiteDist[SIZE];

struct LCA {
	int parent[SIZE][18];
	int depth[SIZE];
	int max_depth = 17;
	void Init() { DFS(1, 1); }

	void DFS(int v, int d) {
		depth[v] = d;
		for (int k = 1; k <= max_depth; k++)
			parent[v][k] = parent[parent[v][k - 1]][k - 1];

		for (auto i : con[v]) {
			if (depth[i] == 0) {
				parent[i][0] = v;
				DFS(i, d + 1);
			}
		}
	}

	int GetDist(int n1, int n2) {
		int d1 = depth[n1], d2 = depth[n2];
		if (depth[n1] > depth[n2])
			swap(n1, n2);

		if (depth[n1] != depth[n2])
			for (int k = max_depth; k >= 0; k--)
				if (depth[n1] <= depth[parent[n2][k]])
					n2 = parent[n2][k];

		int lca;
		if (n1 != n2) {
			for (int k = max_depth; k >= 0; k--) {
				if (parent[n1][k] != parent[n2][k]) {
					n1 = parent[n1][k];
					n2 = parent[n2][k];
				}
			}
			lca = parent[n1][0];
		}
		else
			lca = n1;

		return d1 + d2 - depth[lca] * 2;
	}
} lca;

int SetSize(int v, int prev, int d) {
	sz[v] = 1;
	for (auto i : con[v])
		if (i != prev && !visited[i])
			sz[v] += SetSize(i, v, d + 1);
	return sz[v];
}

int Centroid(int v, int prev, int size) {
	for (auto i : con[v])
		if (i != prev && !visited[i] && sz[i] * 2 > size)
			return Centroid(i, v, size);
	return v;
}

int CTR_Tree(int root) {
	int size = SetSize(root, -1, 0);
	int ctr = Centroid(root, -1, size);
	visited[ctr] = 1;

	for (auto i : con[ctr])
		if (!visited[i])
			parent_ctr[CTR_Tree(i)] = ctr;
	return ctr;
}

void Update(int u) {
	int v = u;
	color[u] = !color[u];

	while (v != -1) {
		if (color[u])
			whiteDist[v].insert(lca.GetDist(v, u));
		else {
			auto i = whiteDist[v].lower_bound(lca.GetDist(v, u));
			if (i != whiteDist[v].end())
				whiteDist[v].erase(i);
		}
		v = parent_ctr[v];
	}
}

int Search(int u) {
	int v = u, minDist = N + 1;
	while (v != -1) {
		auto i = whiteDist[v].begin();
		if (i != whiteDist[v].end())
			minDist = min(minDist, lca.GetDist(v, u) + *i);
		v = parent_ctr[v];
	}
	return (minDist != N + 1) ? minDist : -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	lca.Init();
	int ctr = CTR_Tree(1);
	parent_ctr[ctr] = -1;

	cin >> M;
	while (M--) {
		int q, a;
		cin >> q >> a;
		if (q == 1) Update(a);
		else cout << Search(a) << "\n";
	}
	return 0;
}
