#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;
const int SIZE = 502, INF = 1 << 30;
int N, max_match;
int cost[SIZE][SIZE];
int lx[SIZE], ly[SIZE];
int xy[SIZE], yx[SIZE];
bool S[SIZE], T[SIZE];
int slack[SIZE], slackx[SIZE];
int prevX[SIZE];

void LabelUpdate() {
	int x, y;
	int a = INF;
	for (y = 0; y < N; y++)
		if (!T[y])
			a = min(a, slack[y]);
	for (x = 0; x < N; x++)
		if (S[x])
			lx[x] -= a;
	for (y = 0; y < N; y++)
		if (T[y])
			ly[y] += a;
	for (y = 0; y < N; y++)
		if (!T[y])
			slack[y] -= a;
}

void AddTree(int x, int lastX) {
	S[x] = 1;
	prevX[x] = lastX;
	for (int y = 0; y < N; y++) {
		if (lx[x] + ly[y] - cost[x][y] < slack[y]) {
			slack[y] = lx[x] + ly[y] - cost[x][y];
			slackx[y] = x;
		}
	}
}

void Augment() {
	if (max_match == N) return;
	int x, y, root = 0;
	queue<int> q;

	memset(S, 0, sizeof(S));
	memset(T, 0, sizeof(T));
	memset(prevX, -1, sizeof(prevX));

	for (x = 0; x < N; x++) {
		if (xy[x] == -1) {
			q.push(x);
			root = x;
			prevX[x] = -2;
			S[x] = 1;
			break;
		}
	}

	for (y = 0; y < N; y++) {
		slack[y] = lx[root] + ly[y] - cost[root][y];
		slackx[y] = root;
	}

	while (1) {
		while (!q.empty()) {
			x = q.front(); q.pop();
			for (y = 0; y < N; y++) {
				if (cost[x][y] == lx[x] + ly[y] && !T[y]) {
					if (yx[y] == -1) break;
					T[y] = 1;
					q.push(yx[y]);
					AddTree(yx[y], x);
				}
			}
			if (y < N) break;
		}
		if (y < N) break;

		LabelUpdate();
		q = queue<int>();
		for (y = 0; y < N; y++) {
			if (!T[y] && slack[y] == 0) {
				if (yx[y] == -1) {
					x = slackx[y];
					break;
				}
				else {
					T[y] = 1;
					if (!S[yx[y]]) {
						q.push(yx[y]);
						AddTree(yx[y], slackx[y]);
					}
				}
			}
		}
		if (y < N) break;
	}

	if (y < N) {
		max_match++;
		for (int cx = x, cy = y, ty; cx != -2; cx = prevX[cx], cy = ty) {
			ty = xy[cx];
			yx[cy] = cx;
			xy[cx] = cy;
		}
		Augment();
	}
}

int Hungarian() {
	int ret = 0;
	max_match = 0;
	memset(xy, -1, sizeof(xy));
	memset(yx, -1, sizeof(yx));
	memset(lx, 0, sizeof(lx));
	memset(ly, 0, sizeof(ly));
	for (int x = 0; x < N; x++)
		for (int y = 0; y < N; y++)
			lx[x] = max(lx[x], cost[x][y]);

	Augment();
	for (int x = 0; x < N; x++)
		ret += cost[x][xy[x]];
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> cost[y][x];
			cost[y][x] = -cost[y][x];
		}
	}
	cout << -Hungarian() << "\n";
	return 0;
}
