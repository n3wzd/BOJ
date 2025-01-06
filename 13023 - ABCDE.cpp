#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 2002
using namespace std;
int N, M, V;
bool visited[SIZE];
vector<int> graph[SIZE];

void DFS(int v, int depth) {
	if (depth >= 5) {
		cout << 1;
		exit(0);
	}

	visited[v] = 1;
	for (int i = 0; i < graph[v].size(); i++) {
		int next = graph[v][i];
		if (!visited[next])
			DFS(next, depth + 1);
	}
	visited[v] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	for (int i = 0; i < N; i++)
		DFS(i, 1);
	cout << 0;
	return 0;
}
