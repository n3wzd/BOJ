#include <iostream>
#include <vector>
using namespace std;
class Range {
public:
	int lo, hi;
};
int N, sum = 0;
vector<Range> rectLeft[30001];
vector<Range> rectRight[30001];
int tree[120004], treeL[120004];
const int MAXV = 30000;

void TreeUpdate(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;
	else if (start >= left && end <= right)
		tree[idx] += diff;
	else {
		int mid = (start + end) / 2;
		TreeUpdate(start, mid, idx * 2, left, right, diff);
		TreeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
	}

	if (tree[idx] > 0)
		treeL[idx] = end - start + 1;
	else {
		if (start == end) treeL[idx] = 0;
		else treeL[idx] = treeL[idx * 2] + treeL[idx * 2 + 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, x2;
		Range ran;
		cin >> x1 >> ran.lo >> x2 >> ran.hi;
		rectLeft[x1].push_back(ran);
		rectRight[x2].push_back(ran);
	}

	for (int x = 0; x <= MAXV; x++) {
		int len1 = rectLeft[x].size();
		for (int i = 0; i < len1; i++)
			TreeUpdate(0, MAXV, 1, rectLeft[x][i].lo, rectLeft[x][i].hi - 1, 1);

		int len2 = rectRight[x].size();
		for (int i = 0; i < len2; i++)
			TreeUpdate(0, MAXV, 1, rectRight[x][i].lo, rectRight[x][i].hi - 1, -1);

		sum += treeL[1];
	}
	cout << sum;
	return 0;
}
