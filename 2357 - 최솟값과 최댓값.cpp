#include <iostream>
using namespace std;
const int MAXV = 1000000001, MINV = -1;
int N, M;
int num[100001];

class segTree {
public:
	int tree[400004];
	int type = 0; // 0 - max, 1 - min

	int Operator(int a, int b) {
		if (type == 0) return max(a, b);
		else return min(a, b);
	}

	int Init(int start, int end, int idx) {
		if (start == end) return tree[idx] = num[start];
		int mid = (start + end) / 2;
		return tree[idx] = Operator(Init(start, mid, idx * 2), Init(mid + 1, end, idx * 2 + 1));
	}

	int Get(int start, int end, int idx, int left, int right) {
		if (start > right || end < left) return (type == 0) ? MINV : MAXV;
		if (start >= left && end <= right) return tree[idx];
		int mid = (start + end) / 2;
		return Operator(Get(start, mid, idx * 2, left, right), Get(mid + 1, end, idx * 2 + 1, left, right));
	}
};

segTree maxTree, minTree;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	maxTree.type = 0, minTree.type = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> num[i];
	maxTree.Init(0, N - 1, 1);
	minTree.Init(0, N - 1, 1);

	while (M--) {
		int a, b;
		cin >> a >> b;
		cout << minTree.Get(0, N - 1, 1, a - 1, b - 1) << " " << maxTree.Get(0, N - 1, 1, a - 1, b - 1) << "\n";
	}
	return 0;
}