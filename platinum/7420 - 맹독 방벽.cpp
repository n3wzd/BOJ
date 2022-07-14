#include <iostream>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
typedef long long ll;
const double PI = 3.14159265358979323846;
struct Point { ll x, y; };
int N, L;
Point P[1002];

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

double Distance(Point a, Point b) {
	return sqrt(pow((a.y - b.y), 2) + pow((a.x - b.x), 2));
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

	double dist = 0;
	int first = stk.top();
	while (stk.size() >= 2) {
		int a = stk.top(); stk.pop();
		int b = stk.top();
		dist += Distance(P[a], P[b]);
	}
	dist += Distance(P[first], P[0]);
	cout << round(dist + PI * L * 2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++)
		cin >> P[i].x >> P[i].y;
	Convex();
	return 0;
}
