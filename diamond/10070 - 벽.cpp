#include <iostream>
using namespace std;
const int SIZE = 2e6 + 2, INF = 1e5;
int N, M;
int tree[SIZE * 4];
int lazy[SIZE * 4][2];

void Init(int start, int end, int idx) {
	lazy[idx][0] = 0, lazy[idx][1] = INF;
	if (start == end) return;
	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

void LazyUpdate(int start, int end, int idx) {
	if (tree[idx] < lazy[idx][0]) tree[idx] = lazy[idx][0];
	if (tree[idx] > lazy[idx][1]) tree[idx] = lazy[idx][1];
	if (start != end) {
		for (int i = 0; i < 2; i++) {
			lazy[idx * 2 + i][0] = max(lazy[idx * 2 + i][0], lazy[idx][0]);
			if (lazy[idx * 2 + i][0] > lazy[idx * 2 + i][1])
				lazy[idx * 2 + i][1] = lazy[idx * 2 + i][0];

			lazy[idx * 2 + i][1] = min(lazy[idx * 2 + i][1], lazy[idx][1]);
			if (lazy[idx * 2 + i][1] < lazy[idx * 2 + i][0])
				lazy[idx * 2 + i][0] = lazy[idx * 2 + i][1];
		}
	}
	lazy[idx][0] = 0;
	lazy[idx][1] = INF;
}

int Get(int start, int end, int idx, int pos) {
	LazyUpdate(start, end, idx);
	if (start > pos || end < pos) return 0;
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos);
}

void RangeUpdate(int start, int end, int idx, int left, int right, int op, int value) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		if (op == 1) {
			if (tree[idx] < value) tree[idx] = value;
			if (start != end) {
				for (int i = 0; i < 2; i++) {
					lazy[idx * 2 + i][0] = max(lazy[idx * 2 + i][0], value);
					if (lazy[idx * 2 + i][0] > lazy[idx * 2 + i][1])
						lazy[idx * 2 + i][1] = lazy[idx * 2 + i][0];
				}
			}
		}
		else {
			if (tree[idx] > value) tree[idx] = value;
			if (start != end) {
				for (int i = 0; i < 2; i++) {
					lazy[idx * 2 + i][1] = min(lazy[idx * 2 + i][1], value);
					if (lazy[idx * 2 + i][1] < lazy[idx * 2 + i][0])
						lazy[idx * 2 + i][0] = lazy[idx * 2 + i][1];
				}
			}
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, op, value);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, op, value);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	Init(0, N - 1, 1);
	while (M--) {
		int a, b, c, h;
		cin >> a >> b >> c >> h;
		RangeUpdate(0, N - 1, 1, b, c, a, h);
	}
	for (int i = 0; i < N; i++)
		cout << Get(0, N - 1, 1, i) << "\n";
	return 0;
}
