#include <iostream>
using namespace std;
int N, score, rotateBlock[3] = { 0, 2, 1 };
bool board[2][10][4];

void fallBlock(int id, int t, int x, int y) {
	if (t == 0) {
		while (y < 9 && !board[id][y + 1][x]) y++;
		board[id][y][x] = 1;
	}
	else if (t == 1) {
		while (y < 9 && !board[id][y + 1][x] && !board[id][y + 1][x + 1]) y++;
		board[id][y][x] = board[id][y][x + 1] = 1;
	}
	else if (t == 2) {
		while (y < 8 && !board[id][y + 2][x]) y++;
		board[id][y][x] = board[id][y + 1][x] = 1;
	}
}

void shiftBlock(int id, int Y) {
	for (int y = Y - 1; y >= 0; y--)
		for (int x = 0; x < 4; x++)
			board[id][y + 1][x] = board[id][y][x];
}

void getScore() {
	for (int i = 0; i < 2; i++) {
		for (int y = 6; y < 10; y++) {
			bool ok = 1;
			for (int x = 0; x < 4; x++)
				ok &= board[i][y][x];
			if (ok) {
				score++;
				shiftBlock(i, y);
			}
		}
	}
}

void whiteout() {
	for (int i = 0; i < 2; i++) {
		for (int t = 0; t < 2; t++) {
			bool ok = 0;
			for (int x = 0; x < 4; x++)
				ok |= board[i][5][x];
			if (ok)
				shiftBlock(i, 9);
		}
	}
}

int getAllBlock() {
	int cnt = 0;
	for (int i = 0; i < 2; i++)
		for (int y = 6; y < 10; y++)
			for (int x = 0; x < 4; x++)
				cnt += (board[i][y][x] ? 1 : 0);
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		int t, x, y;
		cin >> t >> y >> x;
		fallBlock(0, t - 1, x, y); fallBlock(1, rotateBlock[t - 1], y, x);
		getScore(); whiteout();
	}
	cout << score << "\n" << getAllBlock();
	return 0;
}
