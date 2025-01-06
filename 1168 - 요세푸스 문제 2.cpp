#include <iostream>
using namespace std;
int N, K, p = 0;
int tree[400004];

int Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = 1;
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

int Find(int start, int end, int idx, int k) {
	if (start == end) return start;
	int mid = (start + end) / 2;
	return (k <= tree[idx * 2]) ? Find(start, mid, idx * 2, k) : Find(mid + 1, end, idx * 2 + 1, k - tree[idx * 2]);
}

int Update(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return tree[idx];
	if (start == end) return tree[idx] += diff;
	int mid = (start + end) / 2;
	return tree[idx] = Update(start, mid, idx * 2, pos, diff) + Update(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	Init(1, N, 1);

	cout << "<";
	int len = N + 1;
	while(--len) {
		p = (p - 1 + K) % len;
		int res = Find(1, N, 1, p + 1);
		Update(1, N, 1, res, -1);
		cout << res;
		if (len > 1) cout << ", ";
	}
	cout << ">";
	return 0;
}
