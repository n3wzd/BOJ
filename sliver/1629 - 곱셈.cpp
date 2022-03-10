#include <iostream>
#include <cmath>
using namespace std;

long long a, b, c, buf = 1;

long long ModMul(long long n1, long long n2)
{
	return ((n1 % c) * (n2 % c)) % c;
}

int main()
{
	cin >> a >> b >> c;

	while (b > 1)
	{
		if (b % 2 != 0) buf = ModMul(buf, a);
		a = ModMul(a, a);
		b /= 2;
	}

	cout << ModMul(a, buf) << endl;
	return 0;
}