#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

class Range {
public:
	int start, end;
	Range() {}
	Range(int a, int b) { start = a, end = b; }
};

int N, M;
vector<int> graph[500001];
Range subtree[500001];
int euler[500001];
ll salary[500001];
ll tree[2000004];
bool visited[500001];
int dfs_num = 0;

void DFS(int v) {
	visited[v] = 1;
	subtree[v].start = ++dfs_num;
	euler[dfs_num] = v;
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (!visited[next])
			DFS(next);
	}
	subtree[v].end = dfs_num;
}

void Init(int start, int end, int idx) {
	if (start == end) {
		tree[idx] = salary[euler[start]];
		return;
	}
	int mid = (start + end) / 2;
	Init(start, mid, idx * 2);
	Init(mid + 1, end, idx * 2 + 1);
}

ll Get(int start, int end, int idx, int pos) {
	if (start > pos || end < pos) return 0;
	if (start == end) return tree[idx];
	int mid = (start + end) / 2;
	return Get(start, mid, idx * 2, pos) + Get(mid + 1, end, idx * 2 + 1, pos) + tree[idx];
}

void Update(int start, int end, int idx, int left, int right, ll diff) {
	if (start > right || end < left) return;
	if (start >= left && end <= right) {
		tree[idx] += diff;
		return;
	}
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, left, right, diff);
	Update(mid + 1, end, idx * 2 + 1, left, right, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cin >> salary[1];
	for (int i = 2; i <= N; i++) {
		int a, b = i;
		cin >> salary[i] >> a;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	DFS(1);
	Init(1, N, 1);

	while (M--) {
		char a;
		int b, c;
		cin >> a;
		if (a == 'p') {
			cin >> b >> c;
			Update(1, N, 1, subtree[b].start + 1, subtree[b].end, c);
		}
		else {
			cin >> b;
			cout << Get(1, N, 1, subtree[b].start) << "\n";
		}
	}
	return 0;
}
