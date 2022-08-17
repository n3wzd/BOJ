#include <iostream>
#include <cmath>
using namespace std;
struct Point { double x, y; };
const int N = 8;
int status[N], id[N], cnt = 0;
double Side(double n) { return n * sqrt(2) / 2; }

bool CCW(Point a, Point b, Point c) {
	double D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D <= 0) ? 1 : 0;
}

Point Dot(int i) {
	double s = status[id[i]];
	if (i == 0) return { 0, s };
	if (i == 1) return { Side(s), Side(s) };
	if (i == 2) return { s, 0 };
	if (i == 3) return { Side(s), -Side(s) };
	if (i == 4) return { 0, -s };
	if (i == 5) return { -Side(s), -Side(s) };
	if (i == 6) return { -s, 0 };
	if (i == 7) return { -Side(s), Side(s) };
	return { 0, 0 };
}

void BT(int visited, int seq) {
	if (seq == N) {
		bool ok = 1;
		for (int i = 0; i < N; i++)
			ok &= CCW(Dot(i), Dot((i + 1) % N), Dot((i + 2) % N));
		if (ok) cnt++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!(visited & (1 << i))) {
			id[seq] = i;
			BT(visited | (1 << i), seq + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < N; i++)
		cin >> status[i];
	BT(0, 0); cout << cnt;
	return 0;
}
