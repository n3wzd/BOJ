#include <iostream>
using namespace std;
int N, Q;
int num[100001];
int tree[400004];
int lazy[400004];

void LazyUpdate(int start, int end, int idx) {
	if (lazy[idx] > 0) {
		tree[idx] = (lazy[idx] % 2 == 0) ? tree[idx] : (end - start + 1) - tree[idx];
		if (start != end) {
			lazy[idx * 2] += lazy[idx];
			lazy[idx * 2 + 1] += lazy[idx];
		}
		lazy[idx] = 0;
	}
}

int Get(int start, int end, int idx, int left, int right) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void RangeUpdate(int start, int end, int idx, int left, int right, int diff) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] = (diff % 2 == 0) ? tree[idx] : (end - start + 1) - tree[idx];
		if (start != end) {
			lazy[idx * 2] += diff;
			lazy[idx * 2 + 1] += diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, diff);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> Q;
	while (Q--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0)	RangeUpdate(1, N, 1, b, c, 1);
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
