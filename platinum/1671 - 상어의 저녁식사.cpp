#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 52
using namespace std;
struct State { int power, speed, intel; };
int N;
vector<int> graph[SIZE];
int matching[SIZE];
bool visited[SIZE];
State shark[SIZE];

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
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> shark[i].power >> shark[i].speed >> shark[i].intel;
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= N; w++) {
			if (shark[i].power == shark[w].power && shark[i].speed == shark[w].speed && shark[i].intel == shark[w].intel) {
				if (i < w)
					graph[i].push_back(w);
			}
			else if (shark[i].power >= shark[w].power && shark[i].speed >= shark[w].speed && shark[i].intel >= shark[w].intel && i != w)
				graph[i].push_back(w);
		}
	}
	
	cout << N - (Bipartite() + Bipartite());
	return 0;
}
