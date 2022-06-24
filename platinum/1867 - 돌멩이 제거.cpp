#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 502
using namespace std;
int N, M;
vector<int> graph[SIZE];
int matching[SIZE];
bool visited[SIZE];

bool DFS(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (visited[nv]) continue;
		visited[nv] = 1;

		if (matching[nv] == 0 || DFS(matching[nv])) {
			matching[nv] = v;
			return 1;
		}
	}
	return 0;
}

int Bipartite() {
	int mat = 0;
	for (int v = 1; v <= N; v++) {
		memset(visited, 0, sizeof(visited));
		if (DFS(v)) mat++;
	}
	return mat;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
	}
	cout << Bipartite();
	return 0;
}
