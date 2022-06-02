#include <iostream>
#include <vector>
using namespace std;

class Range {
public:
	int start, end;
	Range() { start = 0, end = 0; }
	Range(int a, int b) { start = a, end = b; }
};

int N, M;
vector<int> graph[100001];
Range subtree[100001];
int tree[400004];
int lazy[400004];
bool visited[100001];
int dfs_num = 0;
bool direction = 0; // 0 - Top-down, 1 - Bottom-Up

void DFS(int v) {
	visited[v] = 1;
	subtree[v].start = ++dfs_num;
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (!visited[next])
			DFS(next);
	}
	subtree[v].end = dfs_num;
}

int Init(int start, int end, int idx) {
	if (start == end) return tree[idx] = 1;
	int mid = (start + end) / 2;
	return tree[idx] = Init(start, mid, idx * 2) + Init(mid + 1, end, idx * 2 + 1);
}

void LazyUpdate(int start, int end, int idx) {
	if (lazy[idx] != 0) {
		tree[idx] = (lazy[idx] == -1) ? 0 : lazy[idx] * (end - start + 1);
		if (start != end) {
			lazy[idx * 2] = lazy[idx];
			lazy[idx * 2 + 1] = lazy[idx];
		}
		lazy[idx] = 0;
	}
}

int Get(int start, int end, int idx, int left, int right) {
	LazyUpdate(start, end, idx);
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void RangeUpdate(int start, int end, int idx, int left, int right, int value) {
	LazyUpdate(start, end, idx);

	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] = (value == -1) ? 0 : value * (end - start + 1);
		if (start != end) {
			lazy[idx * 2] = value;
			lazy[idx * 2 + 1] = value;
		}
		return;
	}

	int mid = (start + end) / 2;
	RangeUpdate(start, mid, idx * 2, left, right, value);
	RangeUpdate(mid + 1, end, idx * 2 + 1, left, right, value);
	tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int a, b = i;
		cin >> a;
		if (a == 0) continue;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);
	Init(1, N, 1);

	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		if (a == 1)
			RangeUpdate(1, N, 1, subtree[b].start + 1, subtree[b].end, 1);
		else if (a == 2)
			RangeUpdate(1, N, 1, subtree[b].start + 1, subtree[b].end, -1);
		else
			cout << Get(1, N, 1, subtree[b].start + 1, subtree[b].end) << "\n";
	}
	return 0;
}
