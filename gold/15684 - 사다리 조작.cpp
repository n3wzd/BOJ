#include <iostream>
using namespace std;
int N, M, H, depth_max;
bool board[32][11];
const int INF = 4;

bool access() {
	bool ok = true;
	for (int i = 0; i < N; i++) {
		int x = i, y = 0;
		for (; y < H; y++) {
			if (board[y][x])
				x++;
			else if (x > 0 && board[y][x - 1])
				x--;
		}
		ok &= i == x;
		if (!ok)
			break;
	}
	return ok;
}

bool quest(int depth = 0, int bx = 0, int by = 0) {
	if (depth == depth_max)
		return access();

	int x = bx, y = by, res = false;
	for (; x < N - 1; x++) {
		for (; y < H; y++) {
			if (board[y][x] || (x > 0 && board[y][x - 1]) || board[y][x + 1])
				continue;
			board[y][x] = true;
			res |= quest(depth + 1, x, y + 1);
			board[y][x] = false;
			if (res)
				return res;
		}
		y = 0;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> H;
	for (int h = 0; h < M; h++) {
		int x, y;
		cin >> y >> x;
		board[y - 1][x - 1] = true;
	}
	for (int t = 0; t <= 3; t++) {
		depth_max = t;
		if (quest()) {
			cout << t;
			return 0;
		}
	}
	cout << -1;
	return 0;
}
