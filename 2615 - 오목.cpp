#include <iostream>
using namespace std;
const int SIZE = 19;
int board[21][21];
int dy[] = { -1, 0, 1, 1 };
int dx[] = { 1, 1, 1, 0 };

bool Scan(int x, int y, int c) {
	if (c == 0)
		return 0;
	for (int d = 0; d < 4; d++) {
		if (board[y + dy[d] * -1][x + dx[d] * -1] == c)
			continue;

		int sum = 0; bool isOver = 0;
		for (int i = 1; i <= 5; i++) {
			int nx = x + dx[d] * i, ny = y + dy[d] * i;
			if (c == board[ny][nx]) {
				if (i < 5)
					sum++;
				else
					isOver = 1;
			}
		}
		if (sum == 4 && !isOver) {
			cout << c << "\n" << y << " " << x;
			return 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int y = 1; y <= 19; y++)
		for (int x = 1; x <= 19; x++)
			cin >> board[y][x];

	for (int x = 1; x <= 19; x++)
		for (int y = 1; y <= 19; y++)
			if (Scan(x, y, board[y][x]))
				return 0;
		
	cout << 0;
	return 0;
}
