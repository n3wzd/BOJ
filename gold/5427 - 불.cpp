#include <iostream>
#include <memory.h>
#include <queue>
#define SIZE 1002
using namespace std;
int Q, W, H;
int dist[SIZE][SIZE];
int field[SIZE][SIZE];
int dy[] = { 0, 1, 0, -1 };
int dx[] = { 1, 0, -1, 0 };
struct Point { int x, y; };
queue<Point> startFire;

int BFS(int sx, int sy) {
	memset(dist, 0, sizeof(dist));
	queue<Point> playerQ[2], fireQ[2];
	int t = 0;

	while (!startFire.empty()) {
		Point f = startFire.front();
		fireQ[0].push(f);
		dist[f.y][f.x] = 1;
		startFire.pop();
	}
	playerQ[0].push({ sx, sy });
	dist[sy][sx] = 1;

	while (!playerQ[t % 2].empty()) {
		while (!fireQ[t % 2].empty()) {
			Point v = fireQ[t % 2].front();
			int x = v.x, y = v.y;
			fireQ[t % 2].pop();

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx >= W || ny < 0 || ny >= H)
					continue;

				if (dist[ny][nx] == 0 && field[ny][nx] != 1) {
					fireQ[(t + 1) % 2].push({ nx, ny });
					dist[ny][nx] = dist[y][x] + 1;
					field[ny][nx] = 2;
				}
			}
		}

		while (!playerQ[t % 2].empty()) {
			Point v = playerQ[t % 2].front();
			int x = v.x, y = v.y;
			playerQ[t % 2].pop();

			if (x <= 0 || x >= W - 1 || y <= 0 || y >= H - 1)
				return dist[y][x];

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (dist[ny][nx] == 0 && field[ny][nx] == 0) {
					playerQ[(t + 1) % 2].push({ nx, ny });
					dist[ny][nx] = dist[y][x] + 1;
					field[ny][nx] = 1;
				}
			}
		}
		t++;
	}
	return -1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) {
		Point start;
		cin >> W >> H;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++) {
				char c;
				cin >> c;
				if (c == '.')
					field[y][x] = 0;
				if (c == '#')
					field[y][x] = 1;
				if (c == '*') {
					field[y][x] = 2;
					startFire.push({ x, y });
				}
				if (c == '@') {
					field[y][x] = 0;
					start = { x, y };
				}
			}
		}
		int time = BFS(start.x, start.y);
		if (time == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << time << "\n";
	}
	return 0;
}
