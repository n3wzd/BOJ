#include <iostream>
typedef long long ll;
using namespace std;

ll GCD2(ll a, ll b, ll* x, ll* y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = GCD2(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int Q;
	cin >> Q;
	while (Q--) {
		ll x, y, a, b;
		cin >> a >> b;
		ll g = GCD2(a, b, &x, &y);
		while (x >= 0) {
			x -= b, y += a;
		}
		if (g == 1 && y <= 1e9) cout << y << "\n";
		else cout << "IMPOSSIBLE\n";
	}
	return 0;
}
