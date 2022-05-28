#include <iostream>
#include <queue>
using namespace std;

class Point {
public:
	int x, y;
	Point(int a, int b) { x = a, y = b; };
};

int N, K, L;
int board[101][101] = { 1, };
int rot[10001];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };
queue<Point> snake;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		board[y - 1][x - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		int t;
		char c;
		cin >> t >> c;
		if (c == 'L') rot[t] = -1;
		else rot[t] = 1;
	}

	int x = 0, y = 0, d = 0, timer = 0;
	snake.push(Point(x, y));
	while (1) {
		timer++;
		x += dx[d], y += dy[d];
		d = ((d + rot[timer]) + 4) % 4;
		if (x < 0 || x >= N || y < 0 || y >= N) break;
		if (board[y][x] == 1) break;

		snake.push(Point(x, y));
		if (board[y][x] != 2) {
			Point p = snake.front();
			board[p.y][p.x] = 0;
			snake.pop();
		}
		board[y][x] = 1;
	}
	cout << timer;
	return 0;
}
