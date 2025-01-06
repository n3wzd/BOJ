#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
struct Board { int type = 2; vector<int> chess; };
struct Chess { int x, y, d; };
int N, K, G = 1;
Board board[14][14];
Chess chessList[12];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, -1, 1 }, changeDire[4] = { 1, 0, 3, 2 };

bool move(int ax, int ay, int bx, int by, int curId, bool reverse) {
	int len = board[ay][ax].chess.size(), start = -1;
	for (int i = 0; i < len; i++)
		if (board[ay][ax].chess[i] == curId && start == -1)
			start = i;
	for (int i = reverse ? len - 1 : start; reverse ? i >= start : i < len; reverse ? i-- : i++) {
		int id = board[ay][ax].chess[i];
		board[by][bx].chess.push_back(id);
		chessList[id].x = bx, chessList[id].y = by;
	}
	for (int i = len - start; i > 0; i--)
		board[ay][ax].chess.pop_back();
	return board[by][bx].chess.size() >= 4;
}

bool game() {
	for (int id = 0; id < K; id++) {
		Chess cur = chessList[id];
		int nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
		if (board[ny][nx].type == 0)
			if (move(cur.x, cur.y, nx, ny, id, 0))
				return 1;
		if (board[ny][nx].type == 1)
			if (move(cur.x, cur.y, nx, ny, id, 1))
				return 1;
		if (board[ny][nx].type == 2) {
			chessList[id].d = changeDire[chessList[id].d]; cur = chessList[id];
			nx = cur.x + dx[cur.d], ny = cur.y + dy[cur.d];
			if (board[ny][nx].type == 0)
				if (move(cur.x, cur.y, nx, ny, id, 0))
					return 1;
			if (board[ny][nx].type == 1)
				if (move(cur.x, cur.y, nx, ny, id, 1))
					return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> board[y][x].type;
	for (int i = 0; i < K; i++) {
		int x, y, d;
		cin >> y >> x >> d;
		board[y][x].chess.push_back(i);
		chessList[i] = { x, y, d - 1 };
	}
	for (; G <= 1000; G++)
		if (game())
			break;
	cout << (G >= 1000 ? -1 : G);
	return 0;
}
