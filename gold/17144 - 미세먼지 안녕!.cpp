#include <iostream>
using namespace std;

int R, C, T;
int stage[51][51];
int stage_dust[51][51];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int ap1_x = -1, ap1_y, ap2_y;

void DustSpread(int x, int y)
{
	if (stage[y][x] <= 0) return;
	int sp = 0;
	for (int d = 0; d < 4; d++)
	{
		int nx = x + dx[d], ny = y + dy[d];
		if (nx >= 0 && nx < C && ny >= 0 && ny < R && stage[ny][nx] >= 0) {
			stage_dust[ny][nx] += stage[y][x] / 5;
			sp += stage[y][x] / 5;
		}
	}
	stage[y][x] -= sp;
}

void Shift(int mx, int my, int tx, int ty)
{
	if(stage[my][mx] == -1) stage[ty][tx] = 0;
	else if (stage[ty][tx] == -1) return;
	else stage[ty][tx] = stage[my][mx];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> R >> C >> T;
	for (int y = 0; y < R; y++) {
		for (int x = 0; x < C; x++) {
			cin >> stage[y][x];
			if (stage[y][x] == -1 && ap1_x == -1) {
				ap1_x = x, ap1_y = y, ap2_y = y + 1;
			}
		}
	}

	while (T--) {
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				stage_dust[y][x] = 0;
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				DustSpread(x, y);
		for (int y = 0; y < R; y++)
			for (int x = 0; x < C; x++)
				stage[y][x] += stage_dust[y][x];

		// up
		for (int x = ap1_x; x > 0; x--) Shift(x - 1, ap1_y, x, ap1_y);
		for (int y = ap1_y; y > 0; y--) Shift(0, y - 1, 0, y);
		for (int x = 0; x < C - 1; x++) Shift(x + 1, 0, x, 0);
		for (int y = 0; y < ap1_y; y++) Shift(C - 1, y + 1, C - 1, y);
		for (int x = C - 1; x > ap1_x; x--) Shift(x - 1, ap1_y, x, ap1_y);

		// down
		for (int x = ap1_x; x > 0; x--) Shift(x - 1, ap2_y, x, ap2_y);
		for (int y = ap2_y; y < R - 1; y++) Shift(0, y + 1, 0, y);
		for (int x = 0; x < C - 1; x++) Shift(x + 1, R - 1, x, R - 1);
		for (int y = R - 1; y > ap2_y; y--) Shift(C - 1, y - 1, C - 1, y);
		for (int x = C - 1; x > ap1_x; x--) Shift(x - 1, ap2_y, x, ap2_y);
	}

	int dust = 2;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			dust += stage[y][x];
	cout << dust;
	return 0;
}
