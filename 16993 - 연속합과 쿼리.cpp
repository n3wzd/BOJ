#include <iostream>
using namespace std;
const int SIZE = 1e5 + 5;
const int INF = 1 << 29;
struct Node { int all, left, right, center; };
int N, M;
int num[SIZE];
Node tree[SIZE * 4];

Node Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = { num[start], num[start], num[start], num[start] };
	int mid = (start + end) / 2;

	Node L = Init(start, mid, idx * 2);
	Node R = Init(mid + 1, end, idx * 2 + 1);
	return tree[idx] = { L.all + R.all, max(L.left, L.all + R.left), max(R.right, R.all + L.right), 
		max(L.right + R.left, max(L.center, R.center)) };
}

Node Get(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return { 0, -INF, -INF, -INF };
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;

	Node L = Get(start, mid, idx * 2, left, right);
	Node R = Get(mid + 1, end, idx * 2 + 1, left, right);
	return { L.all + R.all, max(L.left, L.all + R.left), max(R.right, R.all + L.right),
		max(L.right + R.left, max(L.center, R.center)) };
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	Init(1, N, 1);

	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		Node node = Get(1, N, 1, a, b);
		cout << max(node.center, max(node.left, node.right)) << "\n";
	}
	return 0;
}
