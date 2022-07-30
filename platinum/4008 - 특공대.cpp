#include <iostream>
using namespace std;
typedef long long ll;
struct Line { ll a, b; }; // y = ax + b
const int SIZE = 1e6 + 2;
ll a, b, c, X[SIZE], cache; int N;

struct CHT {
	int size = 0;
	Line stk[SIZE];

	double Cross(int L1, int L2) {
		return (double)(stk[L1].b - stk[L2].b) / (stk[L2].a - stk[L1].a);
	}

	void Insert(Line v) {
		stk[size] = v;
		while (1 < size && Cross(size - 2, size - 1) > Cross(size - 1, size)) {
			stk[size - 1] = stk[size];
			size--;
		}
		size++;
	}

	ll Search(ll x) {
		int lo = 0, hi = size - 1;
		while (lo < hi) {
			int mid = (lo + hi) / 2;
			if (Cross(mid, mid + 1) <= x)
				lo = mid + 1;
			else hi = mid;
		}
		return stk[lo].a * x + stk[lo].b;
	}
};
CHT cht;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> a >> b >> c;
	for (int i = 1; i <= N; i++) {
		ll x; cin >> x;
		X[i] = X[i - 1] + x;
	}

	cht.Insert({ 0, 0 });
	for (int i = 1; i <= N; i++) {
		cache = cht.Search(X[i]) + (a * X[i] * X[i]) + (b * X[i]) + c;
		cht.Insert({ -2 * a * X[i], (a * X[i] * X[i]) - (b * X[i]) + cache });
	}
	cout << cache;
	return 0;
}
