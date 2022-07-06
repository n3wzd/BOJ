#include <iostream>
using namespace std;
typedef long long ll;
const ll r = 31, M = 1234567891;
ll ModAdd(ll a, ll b) { return ((a % M) + (b % M)) % M; }
ll ModMul(ll a, ll b) {	return ((a % M) * (b % M)) % M; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	ll N, R = 1, hash = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		hash = ModAdd(hash, ModMul(c - 'a' + 1, R));
		R = ModMul(R, r);
	}
	cout << hash;
	return 0;
}
