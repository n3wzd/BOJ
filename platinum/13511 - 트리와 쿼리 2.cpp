#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int N, M;
vector<pair<int, int>> graph[100001];
int parent[100001][17];
ll route_cost[100001][17];
int depth[100001];
const int logM = 16;

void DFS(int v, int d)
{
	depth[v] = d;
	for (int k = 1; k <= logM; k++) {
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
		route_cost[v][k] = route_cost[v][k - 1] + route_cost[parent[v][k - 1]][k - 1];
	}

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		if (depth[next] == 0) {
			parent[next][0] = v;
			route_cost[next][0] = graph[v][i].second;
			DFS(next, d + 1);
		}
	}
}

ll LCA1(int n1, int n2)
{
	ll cost = 0;
	int p1 = n1, p2 = n2;
	if (depth[p1] < depth[p2]) {
		for (int k = logM; k >= 0; k--) {
			if (depth[p1] <= depth[parent[p2][k]]) {
				cost += route_cost[p2][k];
				p2 = parent[p2][k];
			}
		}
	}
	else if (depth[p1] > depth[p2]) {
		for (int k = logM; k >= 0; k--) {
			if (depth[p2] <= depth[parent[p1][k]]) {
				cost += route_cost[p1][k];
				p1 = parent[p1][k];
			}
		}
	}

	if (p1 == p2) return cost;
	for (int k = logM; k >= 0; k--) {
		if (parent[p1][k] != parent[p2][k]) {
			cost += route_cost[p1][k] + route_cost[p2][k];
			p1 = parent[p1][k];
			p2 = parent[p2][k];
		}
	}
	cost += route_cost[p1][0] + route_cost[p2][0];
	return cost;
}

int LCA2(int n1, int n2, int d)
{
	int dist[2] = { 0, 0 }; // 0 - left(n1), 1 - right(n2)
	int p1 = n1, p2 = n2;
	if (depth[p1] < depth[p2]) {
		for (int k = logM; k >= 0; k--) {
			if (depth[p1] <= depth[parent[p2][k]]) {
				p2 = parent[p2][k];
				dist[1] += (1 << k);
			}
		}
	}
	else if (depth[p1] > depth[p2]) {
		for (int k = logM; k >= 0; k--) {
			if (depth[p2] <= depth[parent[p1][k]]) {
				p1 = parent[p1][k];
				dist[0] += (1 << k);
			}
		}
	}

	if (p1 != p2) {
		for (int k = logM; k >= 0; k--) {
			if (parent[p1][k] != parent[p2][k]) {
				p1 = parent[p1][k];
				p2 = parent[p2][k];
				dist[0] += (1 << k);
				dist[1] += (1 << k);
			}
		}
		dist[0]++, dist[1]++;
	}
	
	int t1 = (d <= dist[0]) ? n1 : n2;
	int dd = (d <= dist[0]) ? d : (dist[1] - (d - dist[0]));
	int t2 = t1;
	for (int k = logM; k >= 0; k--)
		if (depth[t1] - dd <= depth[parent[t2][k]])
			t2 = parent[t2][k];
	return t2;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, w;
		cin >> a >> b >> w;
		graph[a].push_back(make_pair(b, w));
		graph[b].push_back(make_pair(a, w));
	}
	DFS(1, 1);

	cin >> M;
	for (int i = 0; i < M; i++) {
		int q, n1, n2, d;
		cin >> q;
		if (q == 1) {
			cin >> n1 >> n2;
			cout << LCA1(n1, n2) << "\n";
		}
		else {
			cin >> n1 >> n2 >> d;
			cout << LCA2(n1, n2, d - 1) << "\n";
		}
	}
	return 0;
}