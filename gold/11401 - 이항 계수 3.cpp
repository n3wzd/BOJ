#include <iostream>
using namespace std;

long long p = 1000000007;
long long cache[3] = { 1, 1, 1 };

long long ModAdd(long long a, long long b)
{
	return ((a % p) + (b % p)) % p;
}

long long ModMul(long long a, long long b)
{
	return ((a % p) * (b % p)) % p;
}

long long FastPow(long long a, long long power)
{
	long long buf = 1;
	while (power > 1)
	{
		if (power % 2 != 0) buf = ModMul(buf, a);
		a = ModMul(a, a);
		power /= 2;
	}
	return ModMul(a, buf);
}

long long ModDiv(long long a, long long b)
{
	return ModMul(a, FastPow(b, p - 2));
}

int main()
{
	long long n, k;
	cin >> n >> k;

	for (int i = 2; i <= n; i++)
	{
		cache[0] = ModMul(cache[0], i);
		if (i == k) cache[1] = cache[0];
		if (i == n - k) cache[2] = cache[0];
	}

	cout << ModDiv(cache[0], ModMul(cache[1], cache[2])) << endl;
	return 0;
}