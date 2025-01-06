#include <iostream>
#include <vector>
#include <memory.h>
#define SIZE 6405
using namespace std;
int Q, N, M, x_cnt;
vector<int> graph[SIZE];
int matching[SIZE];
bool visited[SIZE];
bool room[83][83];

bool DFS(int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		int nv = graph[v][i];
		if (visited[nv]) continue;
		visited[nv] = 1;

		if (matching[nv] == -1 || DFS(matching[nv])) {
			matching[nv] = v;
			return 1;
		}
	}
	return 0;
}

int Bipartite() {
	int mat = 0;
	for (int v = 0; v < N * M; v++) {
		memset(visited, 0, sizeof(visited));
		if (DFS(v)) mat++;
	}
	return mat;
}

int ID(int x, int y) { return y * M + x; }
int dy[3] = { -1, 0, 1 };
int dx[2] = { -1, 1 };
void Scan(int x, int y) {
	if (!room[y][x]) return;
	for (int d1 = 0; d1 < 2; d1++) {
		for (int d2 = 0; d2 < 3; d2++) {
			int nx = x + dx[d1], ny = y + dy[d2];
			if (nx < 0 || nx >= M || ny < 0 || ny >=N) continue;
			if (!room[ny][nx]) continue;
			graph[ID(x, y)].push_back(ID(nx, ny));
		}
	}
}

void Cycle() {
	x_cnt = 0;
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			char c;
			cin >> c;
			room[y][x] = (c == '.') ? 1 : 0;
			if (!room[y][x]) x_cnt++;
		}
	}
	for (int x = 0; x < M; x += 2)
		for (int y = 0; y < N; y++)
			Scan(x, y);
	
	memset(matching, -1, sizeof(matching));
	cout << (N * M - x_cnt) - Bipartite() << "\n";

	for (int x = 0; x < M; x += 2)
		for (int y = 0; y < N; y++)
			graph[ID(x, y)].clear();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) Cycle();
	return 0;
}
