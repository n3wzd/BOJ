#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll ModAdd(ll a, ll b, ll mod) { return ((a % mod) + (b % mod)) % mod; }
ll ModMul(ll a, ll b, ll mod) {	return ((a % mod) * (b % mod)) % mod; }

ll FastPow(ll a, ll pw, ll mod) {
	ll buf = 1;
	while (pw > 1) {
		if (pw % 2 != 0) buf = ModMul(buf, a, mod);
		a = ModMul(a, a, mod); pw /= 2;
	}
	return ModMul(a, buf, mod);
}

bool MillerRabin(ll x, ll a, ll d, ll s) {
	ll ad = FastPow(a, d, x);
	if (ad == 1 || ad == x - 1) return 1;
	for (int p = 1; p < s; p++) {
		ad = ModMul(ad, ad, x);
		if (ad == x - 1) return 1;
	}
	return 0;
}

ll prime_sample[3] = { 2, 7, 61 };
bool isPrime(ll x) {
	ll d = x - 1, s = 0;
	while (d % 2 == 0) {
		d /= 2;	s++;
	}
	for (int i = 0; i < 3; i++) {
		ll a = prime_sample[i];
		if (x == a) return 1;
		if (!MillerRabin(x, a, d, s)) return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, cnt = 0;
	cin >> N;
	while(N--) {
		ll x;
		cin >> x;
		if (isPrime(2 * x + 1)) cnt++;
	}
	cout << cnt;
	return 0;
}
