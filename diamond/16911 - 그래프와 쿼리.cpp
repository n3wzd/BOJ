#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;
const int SIZE = 100002;
struct Edge { int src, dest; };
struct RB { int pos, data; };
int N, M;
map<int, int> con[SIZE];
Edge query[SIZE];

struct Disjoint {
	int pa[SIZE];
	void Init() {
		for (int i = 0; i <= N; i++)
			pa[i] = -1;
	}

	int Find(int n) {
		int p = n;
		while (pa[p] >= 0) p = pa[p];
		return p;
	}

	RB Union(int a, int b) {
		int p1 = Find(a);
		int p2 = Find(b);
		if (p1 == p2) return { 0, 0 };

		RB rb;
		if (pa[p1] < pa[p2]) {
			rb = { p2, pa[p2] };
			pa[p1] += pa[p2];
			pa[p2] = p1;
		}
		else {
			rb = { p1, pa[p1] };
			pa[p2] += pa[p1];
			pa[p1] = p2;
		}
		return rb;
	}

	void Rollback(RB rb) {
		if (rb.data == 0) return;
		pa[pa[rb.pos]] -= rb.data;
		pa[rb.pos] = rb.data;
	}
} dj;

struct SegTree {
	vector<Edge> tree[SIZE * 4];

	void Add(int start, int end, int idx, int left, int right, Edge edge) {
		if (start > right || end < left) return;
		if (start >= left && end <= right) {
			tree[idx].push_back(edge);
			return;
		}
		int mid = (start + end) / 2;
		Add(start, mid, idx * 2, left, right, edge);
		Add(mid + 1, end, idx * 2 + 1, left, right, edge);
	}

	void DC(int start, int end, int idx, int left, int right) {
		stack<RB> stk;
		for (auto& i : tree[idx])
			stk.push(dj.Union(i.src, i.dest));

		if (start == end) {
			Edge e = query[start];
			if (e.src != 0) {
				if (dj.Find(e.src) == dj.Find(e.dest))
					cout << "1\n";
				else
					cout << "0\n";
			}
		}
		else {
			int mid = (start + end) / 2;
			DC(start, mid, idx * 2, left, right);
			DC(mid + 1, end, idx * 2 + 1, left, right);
		}

		while (!stk.empty()) {
			dj.Rollback(stk.top());
			stk.pop();
		}
	}
} seg;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	dj.Init();
	for (int t = 0; t < M; t++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b > c) swap(b, c);

		if (a == 1)
			con[b].emplace(c, t);
		if (a == 2) {
			auto i = con[b].find(c);
			seg.Add(0, M - 1, 1, i->second, t, { b, c });
			con[b].erase(i);
		}
		if (a == 3)	query[t] = { b, c };
		else query[t] = { 0, 0 };
	}
	for (int v = 1; v <= N; v++)
		for (auto i : con[v])
			seg.Add(0, M - 1, 1, i.second, M - 1, { v, i.first });

	seg.DC(0, M - 1, 1, 0, M - 1);
	return 0;
}
