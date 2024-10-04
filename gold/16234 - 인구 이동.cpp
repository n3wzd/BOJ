#include <iostream>
#include <deque>
using namespace std;
struct Field { deque<int> tree; int food = 5, S2D2 = 0; };
int N, M, K, res;
Field board[12][12];
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 }, dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };

void grow(int x, int y) {
	int cnt = 0;
	for (int& t : board[y][x].tree) {
		if (board[y][x].food >= t) {
			board[y][x].food -= t;
			t += 1;
		}
		else
			cnt++;
	}
	while (cnt--) {
		board[y][x].food += board[y][x].tree.back() / 2;
		board[y][x].tree.pop_back();
	}
}

void plant(int x, int y) {
	for (int& t : board[y][x].tree) {
		if (t % 5 == 0) {
			for (int d = 0; d < 8; d++) {
				int nx = x + dx[d], ny = y + dy[d];
				if (nx < 0 || nx >= N || ny < 0 || ny >= N)
					continue;
				board[ny][nx].tree.push_front(1);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x].S2D2;
	while (M--) {
		int x, y, z;
		cin >> y >> x >> z;
		board[y - 1][x - 1].tree.push_front(z);
	}
	while (K--) {
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				grow(x, y);
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				plant(x, y);
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				board[y][x].food += board[y][x].S2D2;
	}
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			res += board[y][x].tree.size();
	cout << res;
	return 0;
}
