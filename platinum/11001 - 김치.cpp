#include <iostream>
typedef long long ll;
using namespace std;
const int SIZE = 1e5 + 2;
ll N, D, T[SIZE], V[SIZE], res = 0;
ll F(ll i, ll j) { return (j - i) * T[j] + V[i]; }

void DC(ll lo, ll hi, ll lo2, ll hi2) {
	if (lo > hi)
		return;
	ll i = (lo + hi) / 2;
	ll v = 0, v_idx = 0;

	for (int j = lo2; j <= hi2; j++) {
		if (F(i, j) > v && abs(j - i) <= D) {
			v = F(i, j);
			v_idx = j;
		}
	}
	res = max(res, v);

	DC(lo, i - 1, lo2, v_idx);
	DC(i + 1, hi, v_idx, hi2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D;
	for (int i = 0; i < N; i++)
		cin >> T[i];
	for (int i = 0; i < N; i++)
		cin >> V[i];
	DC(0, N - 1, 0, N - 1);
	cout << res;
	return 0;
}
