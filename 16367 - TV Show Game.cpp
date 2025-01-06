#include <iostream>
#include <vector>
#include <stack>
#define SIZE 10002
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

void SAT2() {
	Tarjan();
	for (int v = 1; v <= N; v++) {
		if (scc_id[v] == scc_id[v + N]) {
			cout << "-1";
			return;
		}
	}

	for (int v = 1; v <= N; v++) {
		if (scc_id[v] < scc_id[v + N]) cout << "B";
		else cout << "R";
	}
}

int Coverter(int a) {
	return (a > 0) ? a : N - a;
}

int Inverter(int a) {
	return (a > N) ? a - N : a + N;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x[3], ix[3];
		char c[3];
		for (int w = 0; w < 3; w++) {
			cin >> x[w] >> c[w];
			if (c[w] == 'R') x[w] *= -1;
			x[w] = Coverter(x[w]);
			ix[w] = Inverter(x[w]);
		}
		graph[ix[0]].push_back(x[1]);
		graph[ix[1]].push_back(x[0]);
		graph[ix[1]].push_back(x[2]);
		graph[ix[2]].push_back(x[1]);
		graph[ix[0]].push_back(x[2]);
		graph[ix[2]].push_back(x[0]);
	}
	SAT2();
	return 0;
}
