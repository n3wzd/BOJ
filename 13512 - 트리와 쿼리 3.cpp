#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 100002;
int N, M, id = 0, sz[SIZE], depth[SIZE], parent[SIZE];
int top[SIZE], in[SIZE], out[SIZE], in_inv[SIZE];
vector<int> child[SIZE], con[SIZE];
bool visited[SIZE];

struct SegmentTree {
	int tree[SIZE * 4];
	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = N + 1;
		int mid = (start + end) / 2;
		return tree[idx] = min(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return N + 1;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return min(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
	}

	int Update(int start, int end, int idx, int pos) {
		if (start > pos || end < pos) return tree[idx];
		if (start == end) return tree[idx] = (tree[idx] == N + 1) ? start : N + 1;
		int mid = (start + end) / 2;
		return tree[idx] = min(Update(start, mid, idx * 2, pos), Update(mid + 1, end, idx * 2 + 1, pos));
	}
} seg;

void DFS0(int v = 1) {
	visited[v] = 1;
	for (auto i : con[v]) {
		if (visited[i]) continue;
		visited[i] = 1;
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
	out[v] = id;
}

void Update(int a) {
	seg.Update(1, N, 1, in[a]);
}

int Query(int a, int b) {
	int res = N + 1;
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);
		res = min(res, seg.Get(1, N, 1, in[top[a]], in[a]));
		a = parent[top[a]];
	}
	if (depth[a] > depth[b])
		swap(a, b);
	res = min(res, seg.Get(1, N, 1, in[a], in[b]));

	if (res == N + 1) res = -1;
	else res = in_inv[res];
	return res;
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
	DFS0(); DFS1(); DFS2();
	seg.Init(1, N, 1);

	cin >> M;
	while (M--) {
		int q, v;
		cin >> q >> v;
		if (q == 1)	Update(v);
		else cout << Query(1, v) << "\n";
	}
	return 0;
}
