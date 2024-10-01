#include <iostream>
using namespace std;
struct Point { int x, y; };
int N, M, board[9][9], security[9][9], cctv_len = 0;
Point cctv[8];
const int INF = 999;

bool check_boundary(int x, int y) {
	if (x < 0 || x >= M || y < 0 || y >= N)
		return false;
	if (board[y][x] == 6)
		return false;
	return true;
}

void seeing(int bx, int by, int dire, int adder) {
	int dx[4] = { 0, 1, 0, -1 }, dy[4] = { -1, 0, 1, 0 }; // clockwise
	int x = bx, y = by;
	while (check_boundary(x, y)) {
		security[y][x] += adder;
		x += dx[dire], y += dy[dire];
	}
}

int secure_all() {
	int spot = 0;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (security[y][x] == 0 && board[y][x] != 6)
				spot++;
	return spot;
}

int quest(int idx) {
	if (idx >= cctv_len)
		return secure_all();

	int spot = INF, bx = cctv[idx].x, by = cctv[idx].y, type = board[by][bx];
	if (type == 1) {
		for (int d = 0; d < 4; d++) {
			seeing(bx, by, d, 1);
			spot = min(spot, quest(idx + 1));
			seeing(bx, by, d, -1);
		}
	}
	else if (type == 2) {
		for (int d = 0; d < 2; d++) {
			seeing(bx, by, d, 1);
			seeing(bx, by, d + 2, 1);
			spot = min(spot, quest(idx + 1));
			seeing(bx, by, d, -1);
			seeing(bx, by, d + 2, -1);
		}
	}
	else if (type == 3) {
		for (int d = 0; d < 4; d++) {
			seeing(bx, by, d, 1);
			seeing(bx, by, (d + 1) % 4, 1);
			spot = min(spot, quest(idx + 1));
			seeing(bx, by, d, -1);
			seeing(bx, by, (d + 1) % 4, -1);
		}
	}
	else if (type == 4) {
		for (int d = 0; d < 4; d++) {
			seeing(bx, by, d, 1);
			seeing(bx, by, (d + 1) % 4, 1);
			seeing(bx, by, (d + 3) % 4, 1);
			spot = min(spot, quest(idx + 1));
			seeing(bx, by, d, -1);
			seeing(bx, by, (d + 1) % 4, -1);
			seeing(bx, by, (d + 3) % 4, -1);
		}
	}
	else {
		for (int d = 0; d < 4; d++)
			seeing(bx, by, d, 1);
		spot = min(spot, quest(idx + 1));
		for (int d = 0; d < 4; d++)
			seeing(bx, by, d, -1);
	}
	return spot;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			cin >> board[y][x];
			if (board[y][x] >= 1 && board[y][x] <= 5)
				cctv[cctv_len++] = { x, y };
		}
	}
	cout << quest(0);
	return 0;
}
