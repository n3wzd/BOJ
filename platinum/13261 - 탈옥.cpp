#include <iostream>
typedef long long ll;
using namespace std;
const int SIZE = 8002;
const ll INF = 1e18;
ll L, G, S[SIZE], cache[802][SIZE], res;
ll F(ll i, ll j, int k) { return (k == 1 && j > 0) ? INF : (i - j) * (S[i] - S[j]) + cache[k - 1][j]; }

void DC(ll lo, ll hi, ll lo2, ll hi2, int k) {
	if (lo > hi)
		return;
	ll i = (lo + hi) / 2;
	ll v = INF, v_idx = 0;

	for (int j = lo2; j <= hi2; j++) {
		if (i <= j) break;
		if (F(i, j, k) < v) {
			v = F(i, j, k);
			v_idx = j;
		}
	}
	cache[k][i] = v;

	DC(lo, i - 1, lo2, v_idx, k);
	DC(i + 1, hi, v_idx, hi2, k);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> L >> G;
	for (int i = 1; i <= L; i++) {
		ll C; cin >> C;
		S[i] = S[i - 1] + C;
	}
	G = min(L, G);

	for (int k = 1; k <= G; k++)
		DC(0, L, 0, L, k);
	cout << cache[G][L];
	return 0;
}
