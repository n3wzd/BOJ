#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;
struct Point { int x, y; };
int answer = 200, N, maps[101][101], dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
bool visited[101][101];

int BFS(int mn) {
	queue<Point> q, p;
	q.push({ 0, 0 }); visited[0][0] = 1;
	memset(visited, 0, sizeof(visited));
	int mx = max(mn, maps[0][0]);

	while (1) {
		while (!q.empty()) {
			auto c = q.front(); q.pop();
			if (c.x == N - 1 && c.y == N - 1)
				return mx;
			for (int d = 0; d < 4; d++) {
				int nx = c.x + dx[d], ny = c.y + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N || maps[ny][nx] < mn || visited[ny][nx])
					continue;
				if (maps[ny][nx] > mx) {
					p.push({ nx, ny });
					continue;
				}
				q.push({ nx, ny });
				visited[ny][nx] = 1;
			}
		}
		int size = p.size(); mx++;
		while (size--) {
			auto c = p.front(); p.pop();
			maps[c.y][c.x] <= mx ? q.push({ c.x, c.y }) : p.push({ c.x, c.y });
		}
		if (mx > 201)
			return 1e9;
	}
	return mx;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> maps[y][x];
	for (int mn = 0; mn <= maps[0][0]; mn++)
		answer = min(answer, BFS(mn) - mn);
	cout << answer;
	return 0;
}
