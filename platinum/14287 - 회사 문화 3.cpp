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
bool visited[100001];
int dfs_num = 0;

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

int Get(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, left, right) + Get(mid + 1, end, idx * 2 + 1, left, right);
}

void Update(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return;

	tree[idx] += diff;
	if (start == end) return;

	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, pos, diff);
	Update(mid + 1, end, idx * 2 + 1, pos, diff);
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
		cin >> a >> b;
		if (a == 1) {
			cin >> c;
			Update(1, N, 1, subtree[b].start, c);
		}
		else
			cout << Get(1, N, 1, subtree[b].start, subtree[b].end) << "\n";
	}
	return 0;
}
