#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
struct Line { double a, b; int id; }; // y = ax + b
const int SIZE = 1e5 + 2;
const double EPS = 1e-6;
int N, M;
ll minX, maxX;
Line line[SIZE];
bool cmp(Line a, Line b) { return a.a > b.a; }
bool Equal(double a, double b) { return abs(a - b) < EPS; }

struct CHT {
	int size = 0;
	Line stk[SIZE];

	double Cross(int L1, int L2) {
		return (double)(stk[L1].b - stk[L2].b) / (stk[L2].a - stk[L1].a);
	}

	void Insert(Line v) {
		if (size < 1) {
			stk[size++] = v;
			return;
		}
		if (Equal(v.a, stk[size - 1].a)) {
			if (v.b < stk[size - 1].b)
				size--;
			else
				return;
		}
		
		stk[size] = v;
		while (1 < size && Cross(size - 2, size - 1) > Cross(size - 1, size)) {
			stk[size - 1] = stk[size];
			size--;
		}
		size++;
	}

	bool Scan(int mid, double x) {
		double c = Cross(mid, mid + 1);
		return (!Equal(c, x)) ? c < x : stk[mid].a > stk[mid + 1].a;
	}

	int Search(double x) {
		int lo = 0, hi = size - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (Scan(mid, x))
				lo = mid + 1;
			else hi = mid;
		}
		return stk[lo].id;
	}
};
CHT cht;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> maxX >> minX >> N;
	for (int i = 0; i < N; i++) {
		double y1, y2, d;
		cin >> y2 >> y1;
		d = (y2 - y1) / (maxX - minX);
		line[i] = { d, -d * minX + y1, i + 1 };
	}

	sort(line, line + N, cmp);
	for (int i = 0; i < N; i++)
		cht.Insert(line[i]);

	cin >> M;
	for (int i = 0; i < M; i++) {
		double x;
		cin >> x;
		cout << cht.Search(x) << "\n";
	}
	return 0;
}
