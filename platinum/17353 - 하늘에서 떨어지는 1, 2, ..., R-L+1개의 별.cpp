#include <iostream>
using namespace std;
typedef long long ll;
const int SIZE = 1e5 + 5;
int N, M;
ll num[SIZE];
ll tree[SIZE * 4];
ll tree_cnt[SIZE * 4];

void Init(int start, int end, int idx) {
	if (start == end) {
		tree[idx] = num[start];
		return;
	}
	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

ll Get(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos) + tree[idx] + tree_cnt[idx] * ((ll)pos - start);
}

void Update(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += ((ll)start - left + 1);
		tree_cnt[idx]++;
		return;
	}
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, left, right);
	Update(mid + 1, end, idx * 2 + 1, left, right);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	Init(0, N - 1, 1);

	cin >> M;
	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			Update(0, N - 1, 1, b - 1, c - 1);
		}
		else {
			cin >> b;
			cout << Get(0, N - 1, 1, b - 1) << "\n";
		}
	}
	return 0;
}
