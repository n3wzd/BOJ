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
int tree1[400004];
int tree2[400004];
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

int Get1(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;
	if (start == end) return tree1[idx];
	int mid = (start + end) / 2;
	return Get1(start, mid, idx * 2, pos) + Get1(mid + 1, end, idx * 2 + 1, pos) + tree1[idx];
}

void Update1(int start, int end, int idx, int left, int right, int diff) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree1[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	Update1(start, mid, idx * 2, left, right, diff);
	Update1(mid + 1, end, idx * 2 + 1, left, right, diff);
}

int Get2(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree2[idx];
	int mid = (start + end) / 2;
	return Get2(start, mid, idx * 2, left, right) + Get2(mid + 1, end, idx * 2 + 1, left, right);
}

void Update2(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return;

	tree2[idx] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	Update2(start, mid, idx * 2, pos, diff);
	Update2(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b = i;
		cin >> a;
		if (a == -1) continue;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);

	while (M--) {
		int a, b, c;
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			if (direction) Update2(1, N, 1, subtree[b].start, c);
			else Update1(1, N, 1, subtree[b].start, subtree[b].end, c);;
		}
		else if (a == 2) {
			cin >> b;
			cout << Get1(1, N, 1, subtree[b].start) + Get2(1, N, 1, subtree[b].start, subtree[b].end) << "\n";
		}
		else direction = !direction;
	}
	return 0;
}
