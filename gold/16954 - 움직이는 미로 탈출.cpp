#include <iostream>
#include <queue>
using namespace std;
struct Node { int x, y, t; };
queue<Node> q;
string maps[8];
bool visited[8][8][9]; int dx[] = { 0, 1, 0, -1, 0, 1, 1, -1, -1 }, dy[] = { 0, 0, 1, 0, -1, 1, -1, 1, -1 };
bool collide(int x, int y, int t) { return y - t < 0 ? 0 : maps[y - t][x] == '#'; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for(int y = 0; y < 8; y++)
		cin >> maps[y];
	q.push({ 0, 7, 0 }); visited[0][7][0] = 1;
	while (!q.empty()) {
		auto cur = q.front(); q.pop();
		int x = cur.x, y = cur.y, t = cur.t;
		if (t >= 8) {
			cout << 1;
			return 0;
		}
		for (int d = 0; d < 9; d++) {
			int nx = x + dx[d], ny = y + dy[d], nt = t + 1;
			if (nx >= 0 && nx < 8 && ny >= 0 && ny < 8 && !collide(nx, ny, t) && !collide(nx, ny, nt) && !visited[nx][ny][nt]) {
				visited[nx][ny][nt] = 1;
				q.push({ nx, ny, nt });
			}
		}
	}
	cout << 0;
	return 0;
}
