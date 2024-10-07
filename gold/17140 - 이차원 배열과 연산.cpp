#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
struct Node { int n = 0, c = 0; };
int r, c, k, R = 3, C = 3, phase, tmpLen;
int board[102][102], cnt[102];
Node tmp[102];

void updateTmp() {
	tmpLen = 0;
	for (int i = 1; i <= 100; i++)
		if (cnt[i] > 0)
			tmp[tmpLen++] = { i, cnt[i] };
	sort(tmp, tmp + tmpLen, [](const Node& a, const Node& b) { return a.c != b.c ? a.c < b.c : a.n < b.n; });
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> r >> c >> k;
	for (int y = 0; y < R; y++)
		for (int x = 0; x < C; x++)
			cin >> board[y][x];
	while (phase <= 100) {
		if (board[r - 1][c - 1] == k) {
			cout << phase;
			return 0;
		}
		if (R >= C) {
			for (int y = 0; y < R; y++) {
				memset(cnt, 0, sizeof(cnt));
				for (int x = 0; x < C; x++)
					cnt[board[y][x]]++;
				updateTmp();
				for (int i = 0; i < 50; i++) {
					if (i < tmpLen) {
						board[y][i * 2] = tmp[i].n;
						board[y][i * 2 + 1] = tmp[i].c;
					}
					else
						board[y][i * 2 + 1] = board[y][i * 2] = 0;
				}
				C = min(max(C, tmpLen * 2), 100);
			}
		}
		else {
			for (int x = 0; x < C; x++) {
				memset(cnt, 0, sizeof(cnt));
				for (int y = 0; y < R; y++)
					cnt[board[y][x]]++;
				updateTmp();
				for (int i = 0; i < 50; i++) {
					if (i < tmpLen) {
						board[i * 2][x] = tmp[i].n;
						board[i * 2 + 1][x] = tmp[i].c;
					}
					else
						board[i * 2 + 1][x] = board[i * 2][x] = 0;
				}
				R = min(max(R, tmpLen * 2), 100);
			}
		}
		phase++;
	}
	cout << -1;
	return 0;
}
