#include <iostream>
#include <vector>
#include <stack>
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

bool visited[SIZE];
void DFS(int v) {
	if (visited[v]) return;
	visited[v] = 1;
	int len = graph[v].size();
	for (int i = 0; i < len; i++) {
		int next = graph[v][i];
		if (scc_id[v] != scc_id[next]) {
			scc_in[scc_id[next]]++;
			continue;
		}

		if (!visited[next])
			DFS(next);
	}
}

int Trigger() {
	int trig = 0;
	memset(visited, 0, sizeof(visited));

	for (int id = 1; id < scc_idx; id++) {
		int len = scc[id].size();
		for (int w = 0; w < len; w++)
			DFS(scc[id][w]);
		scc[id].clear();
	}

	for (int id = 1; id < scc_idx; id++)
		if (scc_in[id] == 0)
			trig++;

	return trig;
}

void Init() {
	memset(Did, 0, sizeof(Did));
	memset(scc_id, 0, sizeof(scc_id));
	memset(scc_in, 0, sizeof(scc_in));
	scc.clear();
	Did_idx = 0, scc_idx = 1;
	for (int i = 0; i <= N; i++)
		graph[i].clear();
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
			graph[a].push_back(b);
		}

		scc.push_back(vector<int>());
		for (int v = 1; v <= N; v++)
			if (Did[v] == 0)
				Tarjan(v);

		cout << Trigger() << "\n";
	}
	return 0;
}
