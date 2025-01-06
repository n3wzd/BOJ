#include <iostream>
#include <memory.h>
using namespace std;
const int SIZE = 102;
int N, board[SIZE][SIZE];
bool visited[SIZE][SIZE];
int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

void DFS(int x, int y, int h) {
	visited[y][x] = 1;
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= N || ny < 0 || ny >= N)
			continue;
		if (!visited[ny][nx] && board[ny][nx] >= h)
			DFS(nx, ny, h);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];
	
	int safe = 0, cnt = 0;
	for (int h = 100; h >= 0; h--) {
		memset(visited, 0, sizeof(visited));
		cnt = 0;
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < N; x++) {
				if (!visited[y][x] && board[y][x] >= h) {
					DFS(x, y, h);
					cnt++;
				}
			}
		}
		safe = max(safe, cnt);
	}
	cout << safe;
	return 0;
}
