#include <iostream>
using namespace std;
const int MAXV = 100001, MINV = -1;
int T, N, M;

class segTree {
public:
	int tree[400004];
	int type = 0; // 0 - max, 1 - min

	int Operator(int a, int b) {
		if (type == 0) return max(a, b);
		else return min(a, b);
	}

	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = start;
		int mid = (start + end) / 2;
		return tree[idx] = Operator(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return (type == 0) ? MINV : MAXV;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return Operator(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
	}

	int Update(int start, int end, int idx, int pos, int value) {
		if (start > pos || end < pos) return tree[idx];
		if (start == end) return tree[idx] = value;
		int mid = (start + end) / 2;
		return tree[idx] = Operator(Update(start, mid, idx * 2, pos, value), Update(mid + 1, end, idx * 2 + 1, pos, value));
	}
};
segTree maxTree, minTree;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	maxTree.type = 0, minTree.type = 1;
	cin >> T;
	while (T--) {
		cin >> N >> M;
		maxTree.Init(0, N - 1, 1);
		minTree.Init(0, N - 1, 1);

		while (M--) {
			int a, b, c;
			cin >> a >> b >> c;
			if (a == 0) {
				int dvd1 = minTree.Get(0, N - 1, 1, b, b);
				int dvd2 = minTree.Get(0, N - 1, 1, c, c);
				minTree.Update(0, N - 1, 1, b, dvd2);
				minTree.Update(0, N - 1, 1, c, dvd1);
				maxTree.Update(0, N - 1, 1, b, dvd2);
				maxTree.Update(0, N - 1, 1, c, dvd1);
			}
			else {
				int dvd1 = minTree.Get(0, N - 1, 1, b, c);
				int dvd2 = maxTree.Get(0, N - 1, 1, b, c);
				if (dvd1 >= b && dvd1 <= c && dvd2 >= b && dvd2 <= c)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
	}
	return 0;
}
