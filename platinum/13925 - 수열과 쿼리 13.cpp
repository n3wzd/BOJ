#include <iostream>
using namespace std;
typedef long long ll;
const int SIZE = 1e5 + 5, p = 1e9 + 7;
int N, M;
ll num[SIZE];
ll tree[SIZE * 4];
ll lazy[SIZE * 4][2];
ll MA(ll a, ll b) { return ((a % p) + (b % p)) % p; }
ll MM(ll a, ll b) {	return ((a % p) * (b % p)) % p; }

ll Init(int start, int end, int idx) {
	lazy[idx][0] = 1;
	if (start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = MA(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
}

void LazyUpdate(int start, int end, int idx) {
	tree[idx] = MA(MM(lazy[idx][0], tree[idx]), MM(lazy[idx][1], (ll)end - start + 1));
	if (start != end) {
		lazy[idx * 2][0] = MM(lazy[idx * 2][0], lazy[idx][0]);
		lazy[idx * 2][1] = MA(MM(lazy[idx * 2][1], lazy[idx][0]), lazy[idx][1]);
		lazy[idx * 2 + 1][0] = MM(lazy[idx * 2 + 1][0], lazy[idx][0]);
		lazy[idx * 2 + 1][1] = MA(MM(lazy[idx * 2 + 1][1], lazy[idx][0]), lazy[idx][1]);
	}
	lazy[idx][0] = 1;
	lazy[idx][1] = 0;
}

ll Get(int start, int end, int idx, int left, int right) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return MA(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
}

void RangeUpdate(int start, int end, int idx, int left, int right, ll d1, ll d2) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] = MA(MM(d1, tree[idx]), MM(d2, (ll)end - start + 1));
		if (start != end) {
			lazy[idx * 2][0] = MM(lazy[idx * 2][0], d1);
			lazy[idx * 2][1] = MA(MM(lazy[idx * 2][1], d1), d2);
			lazy[idx * 2 + 1][0] = MM(lazy[idx * 2 + 1][0], d1);
			lazy[idx * 2 + 1][1] = MA(MM(lazy[idx * 2 + 1][1], d1), d2);
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, d1, d2);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, d1, d2);
	tree[idx] = MA(tree[idx * 2], tree[idx * 2 + 1]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a >> b >> c;
		if (a <= 3) {
			cin >> d;
			ll d1 = 0, d2 = 0;
			if (a == 1) { d1 = 1, d2 = d; }
			if (a == 2) { d1 = d, d2 = 0; }
			if (a == 3) { d1 = 0, d2 = d; }
			RangeUpdate(1, N, 1, b, c, d1, d2);
		}
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
