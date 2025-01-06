#include <iostream>
using namespace std;

int gcd(int a, int b) // a > b
{
	return (a % b == 0) ? b : gcd(b, a % b);
}

int main()
{
	int len;
	cin >> len;
	for (; len > 0; len--)
	{
		int n1, n2, res;
		cin >> n1 >> n2;
		res = (n1 > n2) ? gcd(n1, n2) : gcd(n2, n1);
		cout << n1 * n2 / res << endl;
	}
	return 0;
}