#include <iostream>
using namespace std;
typedef long long ll;

int N, M, K;
ll num[1000001];
ll tree[4000004];

ll Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = num[start];
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

ll Get(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void Update(int start, int end, int idx, int pos, ll diff) {
	if (start > pos || end < pos) return;

	tree[idx] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff);
	Update(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	int Q = M + K;
	while (Q--) {
		ll a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			Update(1, N, 1, b, c - num[b]);
			num[b] = c;
		}
		else cout << Get(1, N, 1, b, c) << "\n";
	}
	return 0;
}
