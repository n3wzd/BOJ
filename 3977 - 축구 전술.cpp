#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <memory.h>
#define SIZE 100002
using namespace std;
int N, M, T;
int Did[SIZE];
int scc_id[SIZE];
int scc_in[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
vector<vector<int>> scc;
int Did_idx = 0, scc_idx = 1;

int Tarjan(int v) {
	Did[v] = ++Did_idx;
	stk.push(v);
	int minGoal = Did[v];

	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (Did[next] == 0) minGoal = min(minGoal, Tarjan(next));
		else if(scc_id[next] == 0) minGoal = min(minGoal, Did[next]);
	}

	if (minGoal == Did[v]) {
		scc.push_back(vector<int>());
		int t;
		do {
			t = stk.top();
			scc[scc_idx].push_back(t);
			scc_id[t] = scc_idx;
			stk.pop();
		} while (t != v);
		scc_idx++;
	}
	return minGoal;
}

void Scan(int v) {
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (scc_id[v] != scc_id[next])
			scc_in[scc_id[next]]++;
	}
}

void Trigger() {
	int trig = 0, trig_id;
	for (int id = 1; id < scc_idx; id++) {
		int len = scc[id].size();
		for (int d = 0; d < len; d++)
			Scan(scc[id][d]);
	}

	for (int id = 1; id < scc_idx; id++) {
		if (scc_in[id] == 0) {
			trig++;
			trig_id = id;
		}
	}
	
	if (trig == 1) {
		sort(scc[trig_id].begin(), scc[trig_id].end());
		int len = scc[trig_id].size();
		for (int d = 0; d < len; d++)
			cout << scc[trig_id][d] - 1 << "\n";
	}
	else cout << "Confused\n";
	cout << "\n";
}

void Init() {
	memset(Did, 0, sizeof(Did));
	memset(scc_id, 0, sizeof(scc_id));
	memset(scc_in, 0, sizeof(scc_in));
	Did_idx = 0, scc_idx = 1;
	for (int i = 0; i <= N; i++)
		graph[i].clear();
	int len = scc.size();
	for (int i = 0; i < len; i++)
		scc[i].clear();
	scc.clear();
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> N >> M;
		Init();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			graph[++a].push_back(++b);
		}

		scc.push_back(vector<int>());
		for (int v = 1; v <= N; v++)
			if (Did[v] == 0)
				Tarjan(v);

		Trigger();
	}
	return 0;
}
