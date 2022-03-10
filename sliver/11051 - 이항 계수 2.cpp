#include <iostream>
using namespace std;

int cache[1002][1002] = { 0, };
int p = 10007;

int ModAdd(int a, int b)
{
	return ((a % p) + (b % p)) % p;
}

int DP(int n, int r)
{
	if (n < 0 || r < 0) return 0;
	if (r == 0 || n == r) return 1;
	if (cache[n][r] != 0) return cache[n][r];

	cache[n][r] = ModAdd(DP(n - 1, r - 1), DP(n - 1, r));
	return cache[n][r];
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << DP(n, k) << endl;
	return 0;
}