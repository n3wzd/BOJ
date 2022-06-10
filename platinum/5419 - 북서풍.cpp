#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
typedef long long ll;
using namespace std;
class Point {
public:
	int x, y;
	Point() {}
	Point(int a, int b) { x = a, y = b; }
};
int tree[300004];

bool cmp(Point a, Point b) {
	return (a.x != b.x) ? a.x < b.x : a.y > b.y;
}

int TreeGet(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return TreeGet(start, mid, idx * 2, left, right) + TreeGet(mid + 1, end, idx * 2 + 1, left, right);
}

int TreeUpdate(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return tree[idx];
	if (start == end) return tree[idx] += diff;
	int mid = (start + end) / 2;
	return tree[idx] = TreeUpdate(start, mid, idx * 2, pos, diff) + TreeUpdate(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--) {
		int N;
		ll sum = 0;
		vector<Point> island;
		vector<int> Y;
		memset(tree, 0, sizeof(tree));

		cin >> N;
		for (int i = 0; i < N; i++) {
			Point isle;
			cin >> isle.x >> isle.y;
			island.push_back(isle);
			Y.push_back(isle.y);
		}
		sort(island.begin(), island.end(), cmp);

		sort(Y.begin(), Y.end());
		Y.erase(unique(Y.begin(), Y.end()), Y.end());
		for (int i = 0; i < N; i++)
			island[i].y = lower_bound(Y.begin(), Y.end(), island[i].y) - Y.begin();

		for (int i = N - 1; i >= 0; i--) {
			sum += TreeGet(0, N - 1, 1, 0, island[i].y);
			TreeUpdate(0, N - 1, 1, island[i].y, 1);
		}
		cout << sum << "\n";
	}
	return 0;
}
