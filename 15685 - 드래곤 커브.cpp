#include <iostream>
using namespace std;
struct Point { int x, y; };
int N, direction[1025], res;
bool board[103][103];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, -1, 0, 1 };

void dragon_curve(int x, int y, int d, int G) {
	direction[0] = d;
	for (int g = 1; g <= G; g++) {
		int len = 1 << (g - 1);
		for (int i = 0; i < len; i++)
			direction[len + i] = (direction[len - i - 1] + 1) % 4;
	}
	board[y][x] = 1;
	for (int i = 0; i < (1 << G); i++) {
		x += dx[direction[i]], y += dy[direction[i]];
		board[y][x] = 1;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	while (N--) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragon_curve(x, y, d, g);
	}
	for (int y = 0; y <= 100; y++)
		for (int x = 0; x <= 100; x++)
			res += board[y][x] && board[y + 1][x] && board[y][x + 1] && board[y + 1][x + 1] ? 1 : 0;
	cout << res;
	return 0;
}
