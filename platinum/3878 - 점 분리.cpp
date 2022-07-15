#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point { int x, y; };
struct Line { Point p1, p2; };
int Q, N, M;
Point A[102], B[102];

int CCW(Point a, Point b, Point c) {
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

bool Intersect(Point p1, Point p2, Point p3, Point p4) {
	int r1 = CCW(p1, p2, p3), r2 = CCW(p1, p2, p4);
	int r3 = CCW(p3, p4, p1), r4 = CCW(p3, p4, p2);
	bool res;

	if (r1 == 0 || r2 == 0 || r3 == 0 || r4 == 0) {
		if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0) {
			int ranx1 = min(p1.x, p2.x), ranx2 = max(p1.x, p2.x);
			int rany1 = min(p1.y, p2.y), rany2 = max(p1.y, p2.y);
			int ranx3 = min(p3.x, p4.x), ranx4 = max(p3.x, p4.x);
			int rany3 = min(p3.y, p4.y), rany4 = max(p3.y, p4.y);
			res = (p3.x >= ranx1 && p3.x <= ranx2 && p3.y >= rany1 && p3.y <= rany2) ||
				(p4.x >= ranx1 && p4.x <= ranx2 && p4.y >= rany1 && p4.y <= rany2) ||
				(p1.x >= ranx3 && p1.x <= ranx4 && p1.y >= rany3 && p1.y <= rany4) ||
				(p2.x >= ranx3 && p2.x <= ranx4 && p2.y >= rany3 && p2.y <= rany4);
		}
		else {
			if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) ||
				(p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) res = 1;
			else res = r1 != r2 && r3 != r4;
		}
	}
	else res = r1 != r2 && r3 != r4;
	return res;
}

bool cmp1(Point a, Point b) {
	return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

Point cmp2_base;
bool cmp2(Point a, Point b) {
	int D = CCW(a, cmp2_base, b);
	if (D == 1) return 0;
	else if (D == -1) return 1;
	else return (a.y != b.y) ? a.y < b.y : a.x < b.x;
}

void Convex(Point P[], vector<int>* stk, int len) {
	if (len <= 2) {
		for (int i = 0; i < len; i++)
			stk->push_back(i);
		return;
	}
	sort(P, P + len, cmp1);
	cmp2_base = P[0];
	sort(P + 1, P + len, cmp2);

	stk->push_back(0);
	stk->push_back(1);
	for (int i = 2; i < len; i++) {
		while (stk->size() >= 2) {
			int a = stk->back(); stk->pop_back();
			int b = stk->back();
			if (CCW(P[b], P[a], P[i]) == 1) {
				stk->push_back(a);
				break;
			}
		}
		stk->push_back(i);
	}
}

void MakeLine(Point P[], vector<int>* stk, vector<Line>* L) {
	if (stk->size() <= 1)
		return;
	for (int i = 0; i < stk->size() - 1; i++) {
		int a = stk->at(i);
		int b = stk->at(i + 1);
		L->push_back({ P[a], P[b] });
	}
	L->push_back({ P[stk->back()], P[stk->front()] });
}

bool isContain(Point P[], vector<int>* stk, vector<Line>* L) {
	if (L->empty()) return 0;
	bool res = 1;
	int ccw = CCW(P[stk->at(0)], L->at(0).p1, L->at(0).p2);
	for (int a = 0; a < stk->size(); a++)
		for (int b = 0; b < L->size(); b++)
			if (ccw != CCW(P[stk->at(a)], L->at(b).p1, L->at(b).p2))
				res = 0;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++)
			cin >> A[i].x >> A[i].y;
		for (int i = 0; i < M; i++)
			cin >> B[i].x >> B[i].y;
		if (N == 1 && M == 1) {
			cout << "YES\n";
			continue;
		}
		if (N == 1 && M == 2) {
			if (Intersect(A[0], A[0], B[0], B[1])) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if (N == 2 && M == 1) {
			if (Intersect(B[0], B[0], A[0], A[1])) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}
		if (N == 2 && M == 2) {
			if (Intersect(A[0], A[1], B[0], B[1])) cout << "NO\n";
			else cout << "YES\n";
			continue;
		}

		vector<int> cvA, cvB;
		Convex(A, &cvA, N);
		Convex(B, &cvB, M);

		vector<Line> LA, LB;
		MakeLine(A, &cvA, &LA);
		MakeLine(B, &cvB, &LB);

		bool isOverlap = 0;
		for (int a = 0; a < LA.size(); a++)
			for (int b = 0; b < LB.size(); b++)
				if (Intersect(LA[a].p1, LA[a].p2, LB[b].p1, LB[b].p2))
					isOverlap = 1;

		if (isOverlap)
			cout << "NO\n";
		else {
			if (isContain(A, &cvA, &LB) || isContain(B, &cvB, &LA))
				cout << "NO\n";
			else
				cout << "YES\n";
		}
	}
	return 0;
}
