#include <iostream>
using namespace std;
typedef long long ll;
ll cache1[100][100], cache2[1035][1035];
const ll p1 = 97, p2 = 1031, p3 = 97 * 1031;
ll ModAdd(ll a, ll b, ll p) { return ((a % p) + (b % p)) % p; }
ll ModMul(ll a, ll b, ll p) { return ((a % p) * (b % p)) % p; }

void DP() {
	for (int n = 0; n <= p1; n++) {
		cache1[n][0] = cache1[n][n] = 1;
		for (int r = 1; r < n; r++)
			cache1[n][r] = ModAdd(cache1[n - 1][r - 1], cache1[n - 1][r], p1);
	}
	for (int n = 0; n <= p2; n++) {
		cache2[n][0] = cache2[n][n] = 1;
		for (int r = 1; r < n; r++) 
			cache2[n][r] = ModAdd(cache2[n - 1][r - 1], cache2[n - 1][r], p2);
	}
}

ll GetC(ll n, ll r, ll p) {
	ll C = 1;
	while (n > 0) {
		if(p == p1)	C = ModMul(C, cache1[n % p][r % p], p);
		else C = ModMul(C, cache2[n % p][r % p], p);
		n /= p, r /= p;
	}
	return C;
}

ll GCD2(ll a, ll b, ll* x, ll* y) {
	if (a == 0) {
		*x = 0, * y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = GCD2(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

ll ModInv(ll a, ll p) {
	ll x, y;
	GCD2(a, p, &x, &y);
	while (x < 0) x += p;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll Q, inv1, inv2;
	DP(); inv1 = ModInv(p1, p2), inv2 = ModInv(p2, p1);
	cin >> Q;
	while (Q--) {
		ll N, K, C1, C2;
		cin >> N >> K;
		if (N == 0 && K == 1) { cout << "1\n"; continue; }
		if (N + 1 < K || K == 1) { cout << "0\n"; continue; }
		N--, K -= 2;
		C1 = GetC(N, K, p1), C2 = GetC(N, K, p2);
		cout << ModAdd(ModMul(C2, ModMul(inv1, p1, p3), p3), ModMul(C1, ModMul(inv2, p2, p3), p3), p3) << "\n";
	}
	return 0;
}
