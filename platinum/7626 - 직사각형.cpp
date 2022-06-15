#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;
class Rect {
public:
	int x1, x2, y1, y2;
};
class Range {
public:
	int lo, hi;
	Range(int a, int b) { lo = a, hi = b; }
};
int N;
ll sum = 0;
vector<Rect> rects;
vector<Range> rectLeft[400001], rectRight[400001];
vector<ll> X, Y;
ll tree[1600008], treeL[1600008];

void TreeUpdate(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;
	else if (start >= left && end <= right)
		tree[idx] += diff;
	else {
		int mid = (start + end) / 2;
		TreeUpdate(start, mid, idx * 2, left, right, diff);
		TreeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	}

	if (tree[idx] > 0) treeL[idx] = Y[end] - Y[start - 1];
	else {
		if (start == end) treeL[idx] = 0;
		else treeL[idx] = treeL[idx * 2] + treeL[idx * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		Rect rect;
		cin >> rect.x1 >> rect.x2 >> rect.y1 >> rect.y2;
		rects.push_back(rect);
		X.push_back(rect.x1), X.push_back(rect.x2);
		Y.push_back(rect.y1), Y.push_back(rect.y2);
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++) {
		int x1, x2, y1, y2;
		x1 = lower_bound(X.begin(), X.end(), rects[i].x1) - X.begin();
		x2 = lower_bound(X.begin(), X.end(), rects[i].x2) - X.begin();
		y1 = lower_bound(Y.begin(), Y.end(), rects[i].y1) - Y.begin();
		y2 = lower_bound(Y.begin(), Y.end(), rects[i].y2) - Y.begin();
		rectLeft[x1].push_back(Range(y1, y2));
		rectRight[x2].push_back(Range(y1, y2));
	}

	int xlen = X.size();
	for (int x = 0; x < xlen - 1; x++) {
		int len1 = rectLeft[x].size();
		for (int i = 0; i < len1; i++)
			TreeUpdate(1, N * 2, 1, rectLeft[x][i].lo + 1, rectLeft[x][i].hi, 1);

		int len2 = rectRight[x].size();
		for (int i = 0; i < len2; i++)
			TreeUpdate(1, N * 2, 1, rectRight[x][i].lo + 1, rectRight[x][i].hi, -1);

		sum += treeL[1] * (X[x + 1] - X[x]);
	}
	cout << sum;
	return 0;
}
