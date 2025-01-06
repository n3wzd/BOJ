#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1000000007;
ll N;
ll matA[2][2] = { 3, 2, 1, 1 };
ll matBuf[2][2] = { 1, 0, 0, 1 };
ll MM(ll n1, ll n2) { return ((n1 % MOD) * (n2 % MOD)) % MOD; }
ll MA(ll n1, ll n2) { return ((n1 % MOD) + (n2 % MOD)) % MOD; }

void MatMul(ll mat1[][2], ll mat2[][2]) {
	ll matR[2][2] = { 0, 0, 0, 0 };
	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			for (int w = 0; w < 2; w++)
				matR[y][x] = MA(matR[y][x], MM(mat1[y][w], mat2[w][x]));

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			mat1[y][x] = matR[y][x];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	if (N % 2 == 1) {
		cout << 0;
		return 0;
	}
	N /= 2;

	while (N > 1) {
		if (N % 2 != 0) MatMul(matBuf, matA);
		MatMul(matA, matA);
		N /= 2;
	}
	MatMul(matBuf, matA);
	cout << matBuf[0][0];
	return 0;
}
