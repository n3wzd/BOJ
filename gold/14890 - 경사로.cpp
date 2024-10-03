#include <iostream>
using namespace std;
struct Capacity { int gauge, height; };
int N, L, board[102][102], res;
Capacity capacity[102];
int dx[2] = { 1, 0 }, dy[2] = { 0, 1 };

int passage(int sx, int sy, int d) {
	int C = 0;
	for (int i = 0, x = sx, y = sy; i < N; i++, x += dx[d], y += dy[d]) {
		int j = i;
		while (board[y][x] == board[y + dy[d]][x + dx[d]] && i < N)
			i++, x += dx[d], y += dy[d];
		capacity[C++] = { i - j + 1, board[y][x] };
	}
	for (int c = 0; c < C - 1; c++) {
		if (capacity[c + 1].height - capacity[c].height == 1) {
			if (capacity[c].gauge >= L)
				capacity[c].gauge -= L;
			else
				return 0;
		}
		else if (capacity[c + 1].height - capacity[c].height == -1) {
			if (capacity[c + 1].gauge >= L)
				capacity[c + 1].gauge -= L;
			else
				return 0;
		}
		else
			return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> board[y][x];
	for (int x = 0; x < N; x++)
		res += passage(x, 0, 1);
	for (int y = 0; y < N; y++)
		res += passage(0, y, 0);
	cout << res;
	return 0;
}
