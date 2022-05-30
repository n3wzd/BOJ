#include <iostream>
using namespace std;
typedef long long ll;

ll N, M, K;
ll num[1000001];
ll tree[4000004];

ll Init(ll start, ll end, ll idx) {
	if (start == end) return tree[idx] = num[start];
	ll mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

ll Sum(ll start, ll end, ll idx, ll left, ll right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	ll mid = (start + end) / 2;
	return Sum(start, mid, idx * 2, left, right) + Sum(mid + 1, end, idx * 2 + 1, left, right);
}

void Update(ll start, ll end, ll idx, ll pos, ll diff) {
	if (start > pos || end < pos) return;

	tree[idx] += diff;
	if (start == end) return;

	ll mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff);
	Update(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	Init(0, N - 1, 1);

	ll Q = M + K;
	while (Q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			Update(0, N - 1, 1, b - 1, c - num[b - 1]);
			num[b - 1] = c;
		}
		else cout << Sum(0, N - 1, 1, b - 1, c - 1) << "\n";
	}
	return 0;
}
