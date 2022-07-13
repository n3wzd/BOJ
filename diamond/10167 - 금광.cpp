#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE = 3e3 + 5;
const ll INF = (ll)1 << 62;
struct Node { ll all, left, right, center; };
struct Point { int x, y, w; };

int N, maxY = 0;
ll money = 0;
Point gold[SIZE];
vector<int> X, Y;
vector<Point> goldX[SIZE], goldY[SIZE];
Node tree[SIZE * 4];

void Init(int start, int end, int idx) {
	tree[idx] = { 0, 0, 0, 0 };
	if (start == end) return;

	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

Node Update(int start, int end, int idx, int pos, ll add) {
	if (start > pos || end < pos) return tree[idx];
	if (start == end) 
		return tree[idx] = { tree[idx].all + add, tree[idx].left + add, tree[idx].right + add, tree[idx].center + add };
	int mid = (start + end) / 2;

	Node L = Update(start, mid, idx * 2, pos, add);
	Node R = Update(mid + 1, end, idx * 2 + 1, pos, add);
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

void Compress() {
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++) {
		int x = lower_bound(X.begin(), X.end(), gold[i].x) - X.begin();
		int y = lower_bound(Y.begin(), Y.end(), gold[i].y) - Y.begin();
		gold[i].x = x, gold[i].y = y;
		goldY[y].push_back(gold[i]);
		maxY = max(maxY, y);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> gold[i].x >> gold[i].y >> gold[i].w;
		X.push_back(gold[i].x);
		Y.push_back(gold[i].y);
	}
	Compress();

	for (int ys = maxY; ys >= 0; ys--) {
		Init(0, N - 1, 1);
		for (int y = ys; y >= 0; y--) {
			for (int yi = 0; yi < goldY[y].size(); yi++)
				Update(0, N - 1, 1, goldY[y][yi].x, goldY[y][yi].w);
			Node node = Get(0, N - 1, 1, 0, N - 1);
			money = max(money, max(node.center, max(node.left, node.right)));
		}
	}
	cout << money;
	return 0;
}
