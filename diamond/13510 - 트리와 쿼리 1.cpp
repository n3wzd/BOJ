#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100002;
struct Edge { int dest, w, id; };
int N, M, id = 0, sz[SIZE], depth[SIZE], parent[SIZE];
int top[SIZE], in[SIZE], in_inv[SIZE], weight[SIZE], etov[SIZE];
vector<int> child[SIZE];
vector<Edge> con[SIZE];
bool visited[SIZE];

struct SegmentTree {
	int tree[SIZE * 4];
	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = weight[in_inv[start]];
		int mid = (start + end) / 2;
		return tree[idx] = max(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return 0;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return max(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
	}

	int Update(int start, int end, int idx, int pos, int value) {
		if (start > pos || end < pos) return tree[idx];
		if (start == end) return tree[idx] = value;
		int mid = (start + end) / 2;
		return tree[idx] = max(Update(start, mid, idx * 2, pos, value), Update(mid + 1, end, idx * 2 + 1, pos, value));
	}
} seg;

void DFS0(int v = 1) {
	visited[v] = 1;
	for (auto edge : con[v]) {
		int i = edge.dest;
		if (visited[i]) continue;
		visited[i] = 1;

		weight[i] = edge.w;
		etov[edge.id] = i;
		child[v].push_back(i);
		DFS0(i);
	}
}

void DFS1(int v = 1) {
	sz[v] = 1;
	for (auto& i : child[v]) {
		depth[i] = depth[v] + 1;
		parent[i] = v;
		DFS1(i);

		sz[v] += sz[i];
		if (sz[i] > sz[child[v][0]])
			swap(i, child[v][0]);
	}
}

void DFS2(int v = 1) {
	in[v] = ++id;
	in_inv[id] = v;
	for (auto i : child[v]) {
		top[i] = (i == child[v][0]) ? top[v] : i;
		DFS2(i);
	}
}

void Update(int a, int d) {
	seg.Update(1, N, 1, in[etov[a]], d);
}

int Query(int a, int b) {
	int res = 0;
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);
		res = max(res, seg.Get(1, N, 1, in[top[a]], in[a]));
		a = parent[top[a]];
	}
	if (depth[a] > depth[b])
		swap(a, b);
	res = max(res, seg.Get(1, N, 1, in[a] + 1, in[b]));
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		con[a].push_back({ b, w, i });
		con[b].push_back({ a, w, i });
	}
	DFS0(); DFS1(); DFS2();
	seg.Init(1, N, 1);

	cin >> M;
	while (M--) {
		int q, a, b;
		cin >> q >> a >> b;
		if (q == 1)	Update(a, b);
		else cout << Query(a, b) << "\n";
	}
	return 0;
}
