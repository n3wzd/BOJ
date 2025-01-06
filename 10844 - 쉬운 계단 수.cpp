#include <iostream>
using namespace std;

int cache[101][10] = { 0, };
int len = 0;
int p = 1000000000;

int ModAdd(int a, int b)
{
	return ((a % p) + (b % p)) % p;
}

int main()
{
	int cases = 0;
	cin >> len;

	for (int n = 1; n <= 9; n++)
		cache[0][n] = 1;

	for (int i = 1; i < len; i++)
	{
		for (int n = 0; n <= 9; n++)
		{
			if (n == 0) cache[i][n] = cache[i - 1][n + 1];
			else if (n == 9) cache[i][n] = cache[i - 1][n - 1];
			else cache[i][n] = ModAdd(cache[i - 1][n - 1], cache[i - 1][n + 1]);
		}
	}

	for (int n = 0; n <= 9; n++)
		cases = ModAdd(cases, cache[len - 1][n]);

	cout << cases << endl;
	return 0;
}