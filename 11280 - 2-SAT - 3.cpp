#include <iostream>
#include <vector>
#include <stack>
#define SIZE 20002
using namespace std;
int N, M;
int Did[SIZE];
int scc_id[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
int Did_idx = 0, scc_idx = 1;

int DFS(int v) {
	Did[v] = ++Did_idx;
	stk.push(v);
	int minGoal = Did[v];

	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (Did[next] == 0) minGoal = min(minGoal, DFS(next));
		else if (scc_id[next] == 0) minGoal = min(minGoal, Did[next]);
	}

	if (minGoal == Did[v]) {
		int t;
		do {
			t = stk.top();
			scc_id[t] = scc_idx;
			stk.pop();
		} while (t != v);
		scc_idx++;
	}
	return minGoal;
}

void Tarjan() {
	for (int v = 1; v <= N * 2; v++)
		if (Did[v] == 0)
			DFS(v);
}

int SAT2() {
	Tarjan();
	for (int v = 1; v <= N; v++)
		if (scc_id[v] == scc_id[v + N])
			return 0;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, ia, ib;
		cin >> a >> b;

		a = (a > 0) ? a : N - a;
		b = (b > 0) ? b : N - b;
		ia = (a > N) ? a - N : a + N;
		ib = (b > N) ? b - N : b + N;
		graph[ia].push_back(b);
		graph[ib].push_back(a);
	}
	cout << SAT2();
	return 0;
}
