#include <iostream>
using namespace std;
int N;
int tree[8000008];
const int MAXV = 2000000;

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
	cin >> N;
	while (N--) {
		int a, b;
		cin >> a >> b;
		if (a == 1) {
			Update(1, MAXV, 1, b, 1);
		}
		else {
			int res = Find(1, MAXV, 1, b);
			cout << res << "\n";
			Update(1, MAXV, 1, res, -1);
		}
	}
	return 0;
}
