#include <iostream>
using namespace std;
const int SIZE = 502;
int N, M, cnt = 0, max_size = 0;
bool board[SIZE][SIZE], visited[SIZE][SIZE];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int DFS(int x, int y) {
	int size = 1;
	visited[y][x] = 1;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if(nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[ny][nx] && board[ny][nx])
			size += DFS(nx, ny);
	}
	return size;
}

int main() {
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (!visited[y][x] && board[y][x]) {
				max_size = max(max_size, DFS(x, y));
				cnt++;
			}
		}
	}
	cout << cnt << "\n" << max_size;
	return 0;
}

