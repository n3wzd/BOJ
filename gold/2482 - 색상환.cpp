#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int cache[1002][1002];
const int p = 1000000003;

int ModAdd(int a, int b)
{
	return ((a % p) + (b % p)) % p;
}

int DP(int _N, int _K)
{
	if (_N < 0 || _K < 0) return 0;
	for (int n = 1; n <= _N; n++) cache[n][0] = 1;
	for (int n = 1; n <= 2; n++) cache[n][1] = n;

	for (int n = 3; n <= _N; n++)
		for (int k = 1; k <= _K; k++)
			cache[n][k] = ModAdd(cache[n - 2][k - 1], cache[n - 1][k]);

	return cache[_N][_K];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	cout << ModAdd(DP(N - 3, K - 1), DP(N - 1, K));
	return 0;
}