#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
int N, shark = 2, prey, walk, board[22][22], dx[4] = { 0, -1, 1, 0 }, dy[4] = { -1, 0, 0, 1, };
bool visited[22][22];
Point respawn, nextPosList[402];

bool BFS() {
	memset(visited, 0, sizeof(visited));
	queue<Point> q; q.push({ respawn.x, respawn.y }); q.push({ -1, -1 });
	int nextPosLen = 0, dist = 0;
	visited[respawn.y][respawn.x] = 1;

	while (!q.empty()) {
		Point cur = q.front(); q.pop();
		int x = cur.x, y = cur.y;
		if (x == -1) {
			if (nextPosLen == 0)
				break;
			sort(nextPosList, nextPosList + nextPosLen, [](const Point& a, const Point& b) { return a.y == b.y ? a.x < b.x : a.y < b.y; });
			for (int i = 0; i < nextPosLen; i++)
				q.push(nextPosList[i]);
			nextPosLen = 0; dist++;
			q.push({ -1, -1 });
			continue;
		}
		if (board[y][x] != 0 && board[y][x] < shark) {
			board[y][x] = 0;
			prey++;
			if (prey >= shark) {
				prey = 0;
				shark++;
			}
			walk += dist;
			respawn = { x, y };
			return true;
		}
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] || board[ny][nx] > shark)
				continue;
			visited[ny][nx] = 1;
			nextPosList[nextPosLen++] = { nx, ny };
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
			if (board[y][x] == 9) {
				respawn = { x, y };
				board[y][x] = 0;
			}
		}
	}
	while (BFS());
	cout << walk;
	return 0;
}
