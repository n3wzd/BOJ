#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
int N, M, fuel, prevDist, success, board[22][22], dx[4] = { 0, -1, 1, 0 }, dy[4] = { -1, 0, 0, 1, };
bool visited[22][22], driveMode;
Point respawn, goal, customer[402], nextPosList[402];

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
		if (!driveMode && board[y][x] > 0) {
			goal = customer[board[y][x]];
			prevDist = dist;
			board[y][x] = 0;
			driveMode = 1;
			respawn = { x, y };
			return 1;
		}
		if (driveMode && goal.x == x && goal.y == y) {
			if (fuel < dist + prevDist)
				return 0;
			success++;
			fuel += dist - prevDist;
			driveMode = 0;
			respawn = { x, y };
			return 1;
		}
		for (int d = 0; d < 4; d++) {
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] || board[ny][nx] == -1)
				continue;
			visited[ny][nx] = 1;
			nextPosList[nextPosLen++] = { nx, ny };
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> fuel;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
			board[y][x] *= -1;
		}
	}
	cin >> respawn.y >> respawn.x; respawn.y--, respawn.x--;
	for (int i = 1; i <= M; i++) {
		int x, y, gx, gy;
		cin >> y >> x >> gy >> gx;
		board[y - 1][x - 1] = i;
		customer[i] = { gx - 1, gy - 1 };
	}
	while (BFS());
	cout << (success >= M ? fuel : -1);
	return 0;
}
