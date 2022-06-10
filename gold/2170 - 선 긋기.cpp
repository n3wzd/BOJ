#include <iostream>
#include <algorithm>
using namespace std;
class Line {
public:
	int lo, hi;
	Line() {}
	Line(int a, int b) { lo = a, hi = b; }
};
int N, sum = 0;
Line line[1000001];
const int MINV = -1000000001;

bool cmp(Line a, Line b) {
	return a.lo < b.lo;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> line[i].lo >> line[i].hi;
	sort(line, line + N, cmp);

	int lo = MINV, hi = MINV;
	for (int i = 0; i < N; i++) {
		int newLo = line[i].lo, newHi = line[i].hi;
		if (newLo > hi) {
			sum += hi - lo;
			lo = newLo, hi = newHi;
		}
		if (newHi > hi) 
			hi = newHi;
	}
	sum += hi - lo;
	cout << sum;
	return 0;
}
