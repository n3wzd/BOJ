#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
int R, C, date = 0, Lid_len = 0, Lid[2];
int lake[1501][1501];
bool visited[1501][1501];
vector<int> parent;
queue<pair<int, int>> q[2];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int Find(int n) {
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if (parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b) {
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2]) {
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else {
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

void Scan(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx >= C || ny < 0 || ny >= R)
			continue;

		if (lake[y][x] != lake[ny][nx] && lake[ny][nx] >= 0)
			Union(lake[y][x], lake[ny][nx]);
	}
}

bool BFS1(int sx, int sy, int id) {
	int meet = 0;
	q[0].push(make_pair(sx, sy));
	visited[sy][sx] = 1;
	parent.push_back(-1);

	while (!q[0].empty()) {
		pair<int, int> v = q[0].front();
		int x = v.first, y = v.second;
		q[0].pop();

		if (lake[y][x] == -3) {
			Lid[Lid_len++] = id;
			meet++;
		}
		lake[y][x] = id;
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || nx >= C || ny < 0 || ny >= R)
				continue;

			if (!visited[ny][nx]) {
				if (lake[ny][nx] == -2)
					q[1].push(make_pair(x, y));
				else {
					visited[ny][nx] = 1;
					q[0].push(make_pair(nx, ny));
				}
			}
		}
	}
	return meet == 2;
}

void BFS2() {
	date++;
	while (1) {
		int tg = date % 2;
		while (!q[tg].empty()) {
			pair<int, int> v = q[tg].front();
			int x = v.first, y = v.second;
			int id = lake[y][x];
			q[tg].pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i], ny = y + dy[i];
				if (nx < 0 || nx >= C || ny < 0 || ny >= R)
					continue;

				if (!visited[ny][nx]) {
					visited[ny][nx] = 1;
					if (lake[ny][nx] == -2) {
						q[(tg + 1) % 2].push(make_pair(nx, ny));
						lake[ny][nx] = id;
						Scan(nx, ny);
					}
				}
			}
		}
		if (Find(Lid[0]) == Find(Lid[1]))
			return;
		date++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			char c;
			cin >> c;
			if (c == '.') lake[y][x] = -1;
			if (c == 'X') lake[y][x] = -2;
			if (c == 'L') lake[y][x] = -3;
		}
	}

	bool end = 0;
	int id = 0;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			if (!visited[y][x] && lake[y][x] != -2)
				end |= BFS1(x, y, id++);
	if (!end) BFS2();
	cout << date;
	return 0;
}
