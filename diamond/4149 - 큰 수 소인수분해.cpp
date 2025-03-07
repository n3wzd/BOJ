#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
typedef __int128 int128;
ll ModAdd(ll a, ll b, ll mod) { return ((a % mod) + (b % mod)) % mod; }
ll ModMul(ll a, ll b, ll mod) {	return (((int128)a % mod) * ((int128)b % mod)) % mod; }
ll GCD(ll a, ll b) { return (a % b == 0) ? b : GCD(b, a % b); }

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

ll prime_sample[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 };
bool isPrime(ll x) {
	ll d = x - 1, s = 0;
	while (d % 2 == 0) {
		d /= 2;	s++;
	}
	for (int i = 0; i < 12; i++) {
		ll a = prime_sample[i];
		if (x == a) return 1;
		if (!MillerRabin(x, a, d, s)) return 0;
	}
	return 1;
}

vector<ll> factors;
void Pollard(ll n) {
	if (n == 1) return;
	if (n % 2 == 0) {
		factors.push_back(2);
		Pollard(n / 2);
		return;
	}
	if (isPrime(n)) {
		factors.push_back(n);
		return;
	}
	ll a, b, c, g = n;
	auto f = [&](ll x) { return ModAdd(ModMul(x, x, n), c, n); };
	do {
		if (g == n) {
			a = b = rand() % (n - 2);
			c = rand() % 10 + 1;
			g = 1;
		}
		a = f(a);
		b = f(f(b));
		g = GCD(max(a, b) - min(a, b), n);
	} while (g == 1);
	Pollard(g);
	Pollard(n / g);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N; cin >> N;
	Pollard(N);
	sort(factors.begin(), factors.end());
	for (int i = 0; i < factors.size(); i++)
		cout << factors[i] << "\n";
	return 0;
}
