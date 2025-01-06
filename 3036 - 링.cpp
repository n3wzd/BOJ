#include <iostream>
using namespace std;

int gcd(int a, int b) // a > b
{
	return (a % b == 0) ? b : gcd(b, a % b);
}

int main()
{
	int len, base;
	cin >> len >> base;

	for (; len > 1; len--)
	{
		int ring, num_gcd;
		cin >> ring;
		num_gcd = (base > ring) ? gcd(base, ring) : gcd(ring, base);
		cout << base / num_gcd << "/" << ring / num_gcd << endl;
	}
	return 0;
}