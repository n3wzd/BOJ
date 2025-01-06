#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#define SIZE 10002
using namespace std;
int N, M;
int Did[SIZE];
bool scc_ok[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
vector<vector<int>> scc;
int Did_idx = 0, scc_idx;

int DFS(int v) {
	Did[v] = ++Did_idx;
	stk.push(v);
	int minGoal = Did[v];

	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (Did[next] == 0) minGoal = min(minGoal, DFS(next));
		else if(!scc_ok[next]) minGoal = min(minGoal, Did[next]);
	}

	if (minGoal == Did[v]) {
		scc.push_back(vector<int>());
		int t;
		do {
			t = stk.top();
			scc[scc_idx].push_back(t);
			scc_ok[t] = 1;
			stk.pop();
		} while (t != v);
		
		sort(scc[scc_idx].begin(), scc[scc_idx].end());
		scc_idx++;
	}
	return minGoal;
}

bool cmp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

void Print() {
	int len = scc.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++) {
		int len2 = scc[i].size();
		for (int w = 0; w < len2; w++)
			cout << scc[i][w] << " ";
		cout << "-1\n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
	}

	for (int v = 1; v <= N; v++)
		if (Did[v] == 0)
			DFS(v);

	sort(scc.begin(), scc.end(), cmp);
	Print();
	return 0;
}
