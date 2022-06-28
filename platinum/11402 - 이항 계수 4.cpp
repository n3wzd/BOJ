#include <iostream>
using namespace std;
typedef long long ll;
ll cache[2002][2002];
ll N, K, M, C = 1;
ll ModAdd(ll a, ll b) { return ((a % M) + (b % M)) % M; }
ll ModMul(ll a, ll b) { return ((a % M) * (b % M)) % M; }

void DP() {
	for (int n = 0; n <= M; n++) {
		cache[n][0] = cache[n][n] = 1;
		for (int r = 1; r < n; r++)
			cache[n][r] = ModAdd(cache[n - 1][r - 1], cache[n - 1][r]);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K >> M; DP();
	while (N > 0) {
		C = ModMul(C, cache[N % M][K % M]);
		N /= M, K /= M;
	}
	cout << C;
	return 0;
}
