#include <iostream>
typedef long long ll;
using namespace std;

int N, M, K;
ll num[1000001];
ll tree[4000004];
ll lazy[4000004];

ll Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

void LazyUpdate(ll start, ll end, int idx) {
	tree[idx] += (end - start + 1) * lazy[idx];
	if (start != end) {
		lazy[idx * 2] += lazy[idx];
		lazy[idx * 2 + 1] += lazy[idx];
	}
	lazy[idx] = 0;
}

ll Get(ll start, ll end, int idx, ll left, ll right) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	ll mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void RangeUpdate(ll start, ll end, int idx, ll left, ll right, ll diff) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += (end - start + 1) * diff;
		if (start != end) {
			lazy[idx * 2] += diff;
			lazy[idx * 2 + 1] += diff;
		}
		return;
	}

	ll mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, diff);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	int Q = M + K;
	while (Q--) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		if (a == 1) {
			cin >> d;
			RangeUpdate(1, N, 1, b, c, d);
		}
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
