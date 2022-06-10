#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
class Line {
public:
	ll lo, hi;
	Line() {}
	Line(ll a, ll b) { lo = a, hi = b; }
};
ll N, M;
ll sum = 0;
Line line[300001];

bool cmp(Line a, Line b) {
	return a.lo < b.lo;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> line[i].hi >> line[i].lo;
	sort(line, line + N, cmp);

	ll lo = -1, hi = -1;
	for (int i = 0; i < N; i++) {
		ll newLo = line[i].lo, newHi = line[i].hi;
		if (newLo > newHi)
			continue;

		if (newLo > hi) {
			sum += (hi - lo) * 2;
			lo = newLo, hi = newHi;
		}
		if (newHi > hi) 
			hi = newHi;
	}
	sum += (hi - lo) * 2;
	cout << sum + M;
	return 0;
}
