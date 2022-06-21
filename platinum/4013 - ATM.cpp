#include <iostream>
#include <vector>
#include <stack>
#define SIZE 500002
using namespace std;
int N, M, S, P;
int Did[SIZE];
int scc_id[SIZE];
vector<int> graph[SIZE];
stack<int> stk;
int Did_idx = 0, scc_idx = 1;
int ATM[500001];
bool restaurant[500001];

int scc_S, max_cache = 0;
vector<int> scc_graph[SIZE];
int scc_cache[500001];
bool scc_visited[500001];
int scc_ATM[500001];
bool scc_restaurant[500001];

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
			scc_ATM[scc_idx] += ATM[t];
			scc_restaurant[scc_idx] |= restaurant[t];
			if (t == S) scc_S = scc_idx;
			stk.pop();
		} while (t != v);
		scc_idx++;
	}
	return minGoal;
}

void Tarjan() {
	for (int v = 1; v <= N; v++)
		if (Did[v] == 0)
			DFS(v);

	for (int v = 1; v <= N; v++) {
		int len = graph[v].size();
		for (int i = 0; i < len; i++) {
			int next = graph[v][i];
			if (scc_id[v] != scc_id[next])
				scc_graph[scc_id[v]].push_back(scc_id[next]);
		}
	}
}

int DP(int s) {
	if (scc_visited[s]) return scc_cache[s];

	int len = scc_graph[s].size();
	for (int i = 0; i < len; i++)
		scc_cache[s] = max(scc_cache[s], DP(scc_graph[s][i]));

	if (scc_restaurant[s] || scc_cache[s] > 0) {
		if (scc_cache[s] == 0) scc_cache[s]++;
		scc_cache[s] += scc_ATM[s];
	}

	scc_visited[s] = 1;
	return scc_cache[s];
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
	for (int i = 1; i <= N; i++)
		cin >> ATM[i];
	cin >> S >> P;
	for (int i = 0; i < P; i++) {
		int s;
		cin >> s;
		restaurant[s] = 1;
	}
	Tarjan();

	cout << DP(scc_S) - 1;
	return 0;
}
