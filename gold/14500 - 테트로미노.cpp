#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int board[501][501];
bool frame[4][4];
int score = 0;

void Tetris(int w, int h)
{
	for (int y = 0; y <= N - h; y++) {
		for (int x = 0; x <= M - w; x++) {
			int sum = 0;
			for (int dy = 0; dy < h; dy++)
				for (int dx = 0; dx < w; dx++)
					if(frame[dy][dx])
						sum += board[y + dy][x + dx];
			score = max(score, sum);
		}
	}
}

void Init()
{
	for (int dy = 0; dy < 4; dy++)
		for (int dx = 0; dx < 4; dx++)
			frame[dy][dx] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> board[y][x];

	// 1
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[0][2] = 1, frame[0][3] = 1;
	Tetris(4, 1);
	Init(), frame[0][0] = 1, frame[1][0] = 1, frame[2][0] = 1, frame[3][0] = 1;
	Tetris(1, 4);

	// 2
	Init(), frame[0][0] = 1, frame[1][0] = 1, frame[0][1] = 1, frame[1][1] = 1;
	Tetris(2, 2);

	// 3
	Init(), frame[0][0] = 1, frame[1][0] = 1, frame[2][0] = 1, frame[2][1] = 1;
	Tetris(2, 3);
	Init(), frame[1][0] = 1, frame[1][1] = 1, frame[1][2] = 1, frame[0][2] = 1;
	Tetris(3, 2);
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[1][1] = 1, frame[2][1] = 1;
	Tetris(2, 3);
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[0][2] = 1, frame[1][0] = 1;
	Tetris(3, 2);

	Init(), frame[0][1] = 1, frame[1][1] = 1, frame[2][1] = 1, frame[2][0] = 1;
	Tetris(2, 3);
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[0][2] = 1, frame[1][2] = 1;
	Tetris(3, 2);
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[1][0] = 1, frame[2][0] = 1;
	Tetris(2, 3);
	Init(), frame[1][0] = 1, frame[1][1] = 1, frame[1][2] = 1, frame[0][0] = 1;
	Tetris(3, 2);

	// 4
	Init(), frame[1][0] = 1, frame[1][1] = 1, frame[1][2] = 1, frame[0][1] = 1;
	Tetris(3, 2);
	Init(), frame[0][1] = 1, frame[1][1] = 1, frame[2][1] = 1, frame[1][0] = 1;
	Tetris(2, 3);
	Init(), frame[0][0] = 1, frame[0][1] = 1, frame[0][2] = 1, frame[1][1] = 1;
	Tetris(3, 2);
	Init(), frame[0][0] = 1, frame[1][0] = 1, frame[2][0] = 1, frame[1][1] = 1;
	Tetris(2, 3);

	// 5
	Init(), frame[0][0] = 1, frame[1][0] = 1, frame[1][1] = 1, frame[2][1] = 1;
	Tetris(2, 3);
	Init(), frame[1][0] = 1, frame[1][1] = 1, frame[0][1] = 1, frame[0][2] = 1;
	Tetris(3, 2);
	Init(), frame[0][1] = 1, frame[1][0] = 1, frame[1][1] = 1, frame[2][0] = 1;
	Tetris(2, 3);
	Init(), frame[0][0] = 1, frame[1][1] = 1, frame[0][1] = 1, frame[1][2] = 1;
	Tetris(3, 2);

	cout << score;
	return 0;
}
