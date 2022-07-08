#include <iostream>
using namespace std;
const int SIZE = 1002;
const int INF = 1e9;
int N, M;
int mars[SIZE][SIZE];
int cache[SIZE][SIZE][3];
bool visited[SIZE][SIZE][3];

int DP(int x, int y, int v) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return -INF;
	if (x == M - 1 && y == N - 1) 
		return mars[y][x];
	if (visited[y][x][v])
		return cache[y][x][v];

	int mov = DP(x, y + 1, 0);
	if (v != 2)
		mov = max(mov, DP(x + 1, y, 1));
	if (v != 1)
		mov = max(mov, DP(x - 1, y, 2));

	cache[y][x][v] = mars[y][x] + mov;
	visited[y][x][v] = 1;
	return cache[y][x][v];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> mars[y][x];
	cout << DP(0, 0, 0) << "\n";
	return 0;
}
