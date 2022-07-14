#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
struct Point { ll x, y, id; };
int Q, N;
Point P[2002];

int CCW(Point a, Point b, Point c) {
	ll D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

bool cmp1(Point a, Point b) {
	return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

bool cmp2(Point a, Point b) {
	int D = CCW(a, P[0], b);
	if (D == 1) return 0;
	else if (D == -1) return 1;
	else return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

bool cmp3(Point a, Point b) {
	return a.y > b.y;
}

void Convex() {
	sort(P, P + N, cmp1);
	sort(P + 1, P + N, cmp2);

	int r = N - 2;
	while (r > 1) {
		if (CCW(P[r], P[r + 1], P[0]) != 0)
			break;
		r--;
	}
	sort(P + r + 1, P + N, cmp3);

	for (int i = 0; i < N; i++)
		cout << P[i].id << " ";
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> P[i].x >> P[i].y;
			P[i].id = i;
		}
		Convex();
	}
	return 0;
}
