#include <iostream>
#include <vector>
typedef unsigned int ui;
using namespace std;
const int SIZE = 500002;
int N, M, id = 0, sz[SIZE], depth[SIZE], parent[SIZE];
int top[SIZE], in[SIZE], out[SIZE];
vector<int> child[SIZE], con[SIZE];
bool visited[SIZE];

struct SegmentTree {
	ui tree[SIZE * 4];
	ui lazy[SIZE * 4][2];
	void Init(int start, int end, int idx) {
		lazy[idx][0] = 1;
		if (start == end) return;
		int mid = (start + end) / 2;
		Init(start, mid, idx * 2);
		Init(mid + 1, end, idx * 2 + 1);
	}

	void LazyUpdate(int start, int end, int idx) {
		tree[idx] = lazy[idx][0] * tree[idx] + lazy[idx][1] * (end - start + 1);
		if (start != end) {
			lazy[idx * 2][0] = lazy[idx * 2][0] * lazy[idx][0];
			lazy[idx * 2][1] = lazy[idx * 2][1] * lazy[idx][0] + lazy[idx][1];
			lazy[idx * 2 + 1][0] = lazy[idx * 2 + 1][0] * lazy[idx][0];
			lazy[idx * 2 + 1][1] = lazy[idx * 2 + 1][1] * lazy[idx][0] + lazy[idx][1];
		}
		lazy[idx][0] = 1;
		lazy[idx][1] = 0;
	}

	ui Get(int start, int end, int idx, int left, int right) {
		LazyUpdate(start, end, idx);
		if (start > right || end < left) return 0;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
	}

	void RangeUpdate(int start, int end, int idx, int left, int right, ui d1, ui d2) {
		LazyUpdate(start, end, idx);

		if (start > right || end < left) return;
		if (start >= left && end <= right) {
			tree[idx] = d1 * tree[idx] + d2 * (end - start + 1);
			if (start != end) {
				lazy[idx * 2][0] = lazy[idx * 2][0] * d1;
				lazy[idx * 2][1] = lazy[idx * 2][1] * d1 + d2;
				lazy[idx * 2 + 1][0] = lazy[idx * 2 + 1][0] * d1;
				lazy[idx * 2 + 1][1] = lazy[idx * 2 + 1][1] * d1 + d2;
			}
			return;
		}

		int mid = (start + end) / 2;
		RangeUpdate(start, mid, idx * 2, left, right, d1, d2);
		RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, d1, d2);
		tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
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
	for (auto i : child[v]) {
		top[i] = (i == child[v][0]) ? top[v] : i;
		DFS2(i);
	}
	out[v] = id;
}

void Update1(int a, int d1, int d2) {
	seg.RangeUpdate(1, N, 1, in[a], out[a], d1, d2);
}

void Update2(int a, int b, int d1, int d2) {
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);
		seg.RangeUpdate(1, N, 1, in[top[a]], in[a], d1, d2);
		a = parent[top[a]];
	}
	if (depth[a] > depth[b])
		swap(a, b);
	seg.RangeUpdate(1, N, 1, in[a], in[b], d1, d2);
}

ui Query1(int a) {
	return seg.Get(1, N, 1, in[a], out[a]);
}

ui Query2(int a, int b) {
	ui res = 0;
	while (top[a] != top[b]) {
		if (depth[top[a]] < depth[top[b]])
			swap(a, b);
		res += seg.Get(1, N, 1, in[top[a]], in[a]);
		a = parent[top[a]];
	}
	if (depth[a] > depth[b])
		swap(a, b);
	res += seg.Get(1, N, 1, in[a], in[b]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		con[a].push_back(b);
		con[b].push_back(a);
	}
	DFS0(); DFS1(); DFS2();
	seg.Init(1, N, 1);

	while (M--) {
		int q, a, b, v;
		cin >> q;
		if (q == 1) {
			cin >> a >> v;
			Update1(a, 1, v);
		}
		if (q == 2) {
			cin >> a >> b >> v;
			Update2(a, b, 1, v);
		}
		if (q == 3) {
			cin >> a >> v;
			Update1(a, v, 0);
		}
		if (q == 4) {
			cin >> a >> b >> v;
			Update2(a, b, v, 0);
		}
		if (q == 5) {
			cin >> a;
			cout << Query1(a) << "\n";
		}
		if (q == 6) {
			cin >> a >> b;
			cout << Query2(a, b) << "\n";
		}
	}
	return 0;
}
