#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
ll D, P, Q, res, money = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> D >> P >> Q;
	res = max(D, max(P, Q));
	if (Q < P) swap(P, Q);

	for (ll p2 = (D / Q) + 1; p2 >= 0; p2--) {
		ll rest = D - p2 * Q;
		if (rest <= 0) {
			if (abs(rest) < res) {
				money = p2 * Q;
				res = abs(rest);
			}
			continue;
		}

		bool esc = 0;
		for (ll p1 = (rest / P); p1 <= (rest / P) + 1; p1++) {
			ll rest2 = rest - (p1 * P);
			if (rest2 <= 0) {
				if (abs(rest2) < res) {
					money = p2 * Q + p1 * P;
					res = abs(rest2);
				}
				else if (abs(rest2) == res) esc = 1;
			}
		}
		if (res == 0) esc = 1;
		if (esc) break;
	}
	cout << money;
	return 0;
}
