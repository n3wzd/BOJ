#include <iostream>
#include <queue>
using namespace std;
class Range {
public:
	int lo, hi;
	Range(int a, int b) { lo = a, hi = b; }
};
int N, M, sum = 0, T;
int tree[400004];
queue<Range> rectLeft[100001];
queue<Range> rectRight[100001];
queue<int> egg[100001];
const int MAXV = 100000;

int TreeGet(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return TreeGet(start, mid, idx * 2, pos) + TreeGet(mid + 1, end, idx * 2 + 1, pos) + tree[idx];
}

void TreeUpdate(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	TreeUpdate(start, mid, idx * 2, left, right, diff);
	TreeUpdate(mid + 1, end, idx * 2 + 1, left, right, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		sum = 0;
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			int ex, ey;
			cin >> ex >> ey;
			egg[ex].push(ey);

		}
		for (int i = 0; i < M; i++) {
			int x1, x2, y1, y2;
			cin >> x1 >> x2 >> y1 >> y2;
			rectLeft[x1].push(Range(y1, y2));
			rectRight[x2].push(Range(y1, y2));
		}

		for (int x = 0; x <= MAXV; x++) {
			while (!rectLeft[x].empty()) {
				TreeUpdate(0, MAXV, 1, rectLeft[x].front().lo, rectLeft[x].front().hi, 1);
				rectLeft[x].pop();
			}
			while (!egg[x].empty()) {
				sum += TreeGet(0, MAXV, 1, egg[x].front());
				egg[x].pop();
			}
			while (!rectRight[x].empty()) {
				TreeUpdate(0, MAXV, 1, rectRight[x].front().lo, rectRight[x].front().hi, -1);
				rectRight[x].pop();
			}
		}
		cout << sum << "\n";
	}
	return 0;
}
