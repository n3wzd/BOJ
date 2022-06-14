#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Range {
public:
	int lo, hi;
};
int N;
Range circuit[100001];
vector<int> Y;
vector<int> cLeft[200001];
int cRight[200001];
int tree[800008];
int lazy[800008];

void LazyUpdate(int start, int end, int idx) {
	if (lazy[idx] != 0) {
		tree[idx] += lazy[idx];
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
	return max(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
}

void RangeUpdate(int start, int end, int idx, int left, int right, int diff) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += diff;
		if (start != end) {
			lazy[idx * 2] += diff;
			lazy[idx * 2 + 1] += diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, diff);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	tree[idx] = max(tree[idx * 2], tree[idx * 2 + 1]);
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		circuit[i].lo = y2, circuit[i].hi = y1;
		Y.push_back(y1), Y.push_back(y2);
	}
	
	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++) {
		circuit[i].lo = lower_bound(Y.begin(), Y.end(), circuit[i].lo) - Y.begin();
		circuit[i].hi = lower_bound(Y.begin(), Y.end(), circuit[i].hi) - Y.begin();
		RangeUpdate(0, N * 2, 1, circuit[i].lo, circuit[i].hi, 1);
		cLeft[circuit[i].lo].push_back(i), cRight[circuit[i].hi]++;
	}

	int cmax = 0, laser1 = 0, len, laser2;
	for (int y = 0; y <= N * 2; y++) {
		len = cLeft[y].size();
		for (int t = 0; t < len; t++) {
			RangeUpdate(0, N * 2, 1, circuit[cLeft[y][t]].lo, circuit[cLeft[y][t]].hi, -1);
			laser1++;
		}
		laser2 = Get(0, N * 2, 1, y, N * 2);
		cmax = max(cmax, laser2 + laser1);
		laser1 -= cRight[y];
	}

	cout << cmax;
	return 0;
}
