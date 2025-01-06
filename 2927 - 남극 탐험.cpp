#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 30002;
struct Query { int q, a, b; bool complete; };
int N, M, id = 0, sz[SIZE], depth[SIZE], parent[SIZE];
int top[SIZE], in[SIZE], in_inv[SIZE], weight[SIZE];
vector<int> child[SIZE], con[SIZE];
bool visited[SIZE];
Query query[SIZE * 10];

struct SegmentTree {
	int tree[SIZE * 4];
	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = weight[in_inv[start]];
		int mid = (start + end) / 2;
		return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return 0;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
	}

	int Update(int start, int end, int idx, int pos, int value) {
		if (start > pos || end < pos) return tree[idx];
		if (start == end) return tree[idx] = value;
		int mid = (start + end) / 2;
		return tree[idx] = Update(start, mid, idx * 2, pos, value) + Update(mid + 1, end, idx * 2 + 1, pos, value);
	}
} seg;

struct Disjoint {
	int pa[SIZE];
	void Init() {
		for (int i = 0; i <= N; i++)
			pa[i] = -1;
	}

	int Find(int n) {
		int p = n;
		while (pa[p] >= 0) p = pa[p];
		if (pa[n] >= 0) pa[n] = p;
		return p;
	}

	void Union(int a, int b) {
		int p1 = Find(a);
		int p2 = Find(b);
		if (p1 == p2) return;

		if (pa[p1] < pa[p2]) {
			pa[p1] += pa[p2];
			pa[p2] = p1;
		}
		else {
			pa[p2] += pa[p1];
			pa[p1] = p2;
		}
	}
} disjoint;

void DFS0(int v) {
	visited[v] = 1;
	for (auto i : con[v]) {
		if (visited[i]) continue;
		visited[i] = 1;
		child[v].push_back(i);
		DFS0(i);
	}
}

void DFS1(int v) {
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

void DFS2(int v) {
	in[v] = ++id;
	in_inv[id] = v;
	for (auto i : child[v]) {
		top[i] = (i == child[v][0]) ? top[v] : i;
		DFS2(i);
	}
}

void Update(int a, int d) {
	seg.Update(1, N, 1, in[a], d);
}

int Get(int a, int b) {
	int res = 0;
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
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];
	disjoint.Init();

	cin >> M;
	for (int i = 1; i <= M; i++) {
		string cmd;
		int q = 0, a, b; bool com = 0;
		cin >> cmd >> a >> b;
		if (cmd == "bridge") q = 1;
		if (cmd == "penguins") q = 2;
		if (cmd == "excursion") q = 3;

		if (q == 1) {
			if (disjoint.Find(a) != disjoint.Find(b)) {
				disjoint.Union(a, b);
				con[a].push_back(b);
				con[b].push_back(a);
				com = 1;
			}
		}
		if (q == 3)
			if (disjoint.Find(a) != disjoint.Find(b))
				com = 1;
		query[i] = { q, a, b, com };
	}
	for (int v = 1; v <= N; v++) if (!visited[v]) DFS0(v);
	for (int v = 1; v <= N; v++) if (sz[v] == 0) DFS1(v);
	for (int v = 1; v <= N; v++) if (in[v] == 0) DFS2(v);
	seg.Init(1, N, 1);

	for (int i = 1; i <= M; i++) {
		if (query[i].complete) {
			if (query[i].q == 1)
				cout << "yes\n";
			else
				cout << "impossible\n";
		}
		else {
			if (query[i].q == 1)
				cout << "no\n";
			else if (query[i].q == 2) 
				Update(query[i].a, query[i].b);
			else
				cout << Get(query[i].a, query[i].b) << "\n";
		}
	}
	return 0;
}
