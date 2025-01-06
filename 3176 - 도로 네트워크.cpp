#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<pair<int, int>> graph[100001];
int parent[100001][17];
int route_max[100001][17];
int route_min[100001][17];
int depth[100001];
const int logM = 16;

void DFS(int v, int d)
{
	depth[v] = d;
	for (int k = 1; k <= logM; k++) {
		parent[v][k] = parent[parent[v][k - 1]][k - 1];
		route_max[v][k] = max(route_max[v][k - 1], route_max[parent[v][k - 1]][k - 1]);
		route_min[v][k] = min(route_min[v][k - 1], route_min[parent[v][k - 1]][k - 1]);
	}

	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i].first;
		if (depth[next] == 0) {
			parent[next][0] = v;
			route_max[next][0] = graph[v][i].second;
			route_min[next][0] = graph[v][i].second;
			DFS(next, d + 1);
		}
	}
}

pair<int, int> LCA(int n1, int n2)
{
	int rmax = 0, rmin = 1000001;

	if (depth[n1] > depth[n2]) {
		int temp = n1;
		n1 = n2;
		n2 = temp;
	}

	if (depth[n1] != depth[n2]) {
		for (int k = logM; k >= 0; k--) {
			if (depth[n1] <= depth[parent[n2][k]]) {
				rmax = max(rmax, route_max[n2][k]);
				rmin = min(rmin, route_min[n2][k]);
				n2 = parent[n2][k];
			}
		}
	}

	if (n1 == n2) return make_pair(rmax, rmin);
	for (int k = logM; k >= 0; k--) {
		if (parent[n1][k] != parent[n2][k]) {
			rmax = max(rmax, max(route_max[n1][k], route_max[n2][k]));
			rmin = min(rmin, min(route_min[n1][k], route_min[n2][k]));
			n1 = parent[n1][k];
			n2 = parent[n2][k];
		}
	}
	rmax = max(rmax, max(route_max[n1][0], route_max[n2][0]));
	rmin = min(rmin, min(route_min[n1][0], route_min[n2][0]));
	return make_pair(rmax, rmin);
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
		int n1, n2;
		cin >> n1 >> n2;
		pair<int, int> res = LCA(n1, n2);
		cout << res.second << " " << res.first << "\n";
	}
	return 0;
}