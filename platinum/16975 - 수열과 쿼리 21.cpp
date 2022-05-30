#include <iostream>
using namespace std;
typedef long long ll;
int N, M;
ll num[100001];
ll tree[400004];

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
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos) + tree[idx];
}

void Update(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, left, right, diff);
	Update(mid + 1, end, idx * 2 + 1, left, right, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	Init(0, N - 1, 1);

	cin >> M;
	while (M--) {
		int a, b, c, d;
		cin >> a >> b;
		if (a == 1) {
			cin >> c >> d;
			Update(0, N - 1, 1, b - 1, c - 1, d);
		}
		else
			cout << Get(0, N - 1, 1, b - 1) << "\n";
	}
	return 0;
}
