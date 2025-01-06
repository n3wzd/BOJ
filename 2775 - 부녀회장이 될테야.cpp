#include <iostream>
using namespace std;

int cache[16][16] = { 0, };

int DP(int k, int n)
{
	if (k == 0) return n;
	if (cache[k][n] != 0) return cache[k][n];

	for (int i = 1; i <= n; i++)
		cache[k][n] += DP(k - 1, i);
	return cache[k][n];
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int k, n, sum = 0;
		cin >> k >> n;
		cout << DP(k, n) << endl;
	}

	return 0;
}