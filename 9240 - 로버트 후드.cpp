#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
const int SIZE = 100002;
struct Point { int x, y; };
Point operator-(Point a, Point b) { return { a.x - b.x, a.y - b.y }; }
int N, cvx[SIZE], cvx_N, minpx, maxpx;
Point P[SIZE];
double Distance(Point a, Point b) { return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)); }

int CCW(Point a, Point b, Point c) {
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
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

void Convex() {
	sort(P, P + N, cmp1);
	sort(P + 1, P + N, cmp2);

	stack<int> stk;
	stk.push(0);
	stk.push(1);
	for (int i = 2; i < N; i++) {
		while (stk.size() >= 2) {
			int a = stk.top(); stk.pop();
			int b = stk.top();
			if (CCW(P[b], P[a], P[i]) == 1) {
				stk.push(a);
				break;
			}
		}
		stk.push(i);
	}

	cvx_N = stk.size();
	int minX = 1000, maxX = -1000;
	for (int i = cvx_N - 1; i >= 0; i--) {
		cvx[i] = stk.top(); stk.pop();
		if (minX > P[cvx[i]].x) {
			minX = P[cvx[i]].x;
			minpx = i;
		}
		if (maxX < P[cvx[i]].x) {
			maxX = P[cvx[i]].x;
			maxpx = i;
		}
	}
}

double Calipers() {
	double maxDist = 0;
	int p1 = minpx, p2 = maxpx;
	for (int i = 0; i < cvx_N; i++) {
		maxDist = max(maxDist, Distance(P[cvx[p1]], P[cvx[p2]]));
		if (CCW({ P[cvx[(p1 + 1) % cvx_N]] - P[cvx[p1]] }, { 0, 0 }, P[cvx[p2]] - P[cvx[(p2 + 1) % cvx_N]]) > 0)
			p2 = (p2 + 1) % cvx_N;
		else
			p1 = (p1 + 1) % cvx_N;
	}
	return maxDist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << fixed; cout.precision(8);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> P[i].x >> P[i].y;
	Convex();
	cout << Calipers();
	return 0;
}
