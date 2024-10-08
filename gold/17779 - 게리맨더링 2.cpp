#include <iostream>
using namespace std;
struct Point { int x, y; };
const int INF = 999999;
int N, res = INF, board[22][22], cnt[5];

int search(int bx, int by, int d1, int d2) {
	if (!(by + d1 + d2 < N && 0 <= bx - d1 && bx + d2 < N))
		return INF;
	for (int i = 0; i < 5; ++i)
		cnt[i] = 0;

	int vl = 0, vr = 0;
	for (int y = 0; y < N; y++) {
		if (y >= by && y <= by + d1) vl--;
		if (y > by + d1 && y <= by + d1 + d2) vl++;
		if (y > by && y <= by + d2)	vr++;
		if (y > by + d2 && y <= by + d1 + d2 + 1) vr--;
		for (int x = 0; x < N; x++) {
			if (x <= bx + vl) {
				if (y < by + d1)
					cnt[0] += board[y][x];
				else
					cnt[2] += board[y][x];
			}
			else if (x > bx + vr) {
				if (y <= by + d2)
					cnt[1] += board[y][x];
				else
					cnt[3] += board[y][x];
			}
			else
				cnt[4] += board[y][x];
		}
	}
	int maxCnt = -1, minCnt = INF;
	for (int i = 0; i < 5; ++i) {
		maxCnt = max(maxCnt, cnt[i]);
		minCnt = min(minCnt, cnt[i]);
	}
	return maxCnt - minCnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> board[y][x];
		}
	}
	for (int d1 = 1; d1 < N; d1++)
		for (int d2 = 1; d2 < N; d2++)
			for (int y = 0; y < N; y++)
				for (int x = 0; x < N; x++)
					res = min(res, search(x, y, d1, d2));
	cout << res;
	return 0;
}
