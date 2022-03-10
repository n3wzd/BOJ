#include <iostream>
#include <cmath>
using namespace std;

int grape[10001] = { 0, };
int cache[10001][3] = { 0, };
bool cache_ck[10001][3] = { 0, };

int DP(int i, int combo)
{
	if (i < 0 || combo > 1) return 0;
	if (i <= 1) grape[i];
	if (cache_ck[i][combo]) return cache[i][combo];

	cache[i][combo] = grape[i] + max(DP(i - 1, combo + 1), max(DP(i - 2, 0), DP(i - 3, 0)));
	cache_ck[i][combo] = true;
	return cache[i][combo];
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> grape[i];

	cout << max(DP(n - 1, 0), DP(n - 2, 0)) << endl;
	return 0;
}