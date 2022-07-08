#include <iostream>
using namespace std;
const int M = 1e9 + 7;
const int SIZE = 100002;
int N, K;
int tree[10][SIZE * 4];
int MA(int a, int  b) { return ((a % M) + (b % M)) % M; }

int Get(int start, int end, int idx, int left, int right, int k) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[k][idx];
	int mid = (start + end) / 2;
	return MA(Get(start, mid, idx * 2, left, right, k), Get(mid + 1, end, idx * 2 + 1, left, right, k));
}

void Update(int start, int end, int idx, int pos, int diff, int k) {
	if (start > pos || end < pos) return;

	tree[k][idx] = MA(tree[k][idx], diff);
	if (start == end) return;

	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff, k);
	Update(mid + 1, end, idx * 2 + 1, pos, diff, k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		Update(1, N, 1, num, 1, 0);
		for (int k = 1; k < K; k++)
			Update(1, N, 1, num, Get(1, N, 1, 1, num - 1, k - 1), k);
	}
	cout << Get(1, N, 1, 1, N, K - 1);
	return 0;
}
