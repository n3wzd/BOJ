#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> divisor;
int num[101];

int gcd(int a, int b) // a > b
{
	return (a % b == 0) ? b : gcd(b, a % b);
}

int main()
{
	int n, gcdv = 1, size;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 1; i < n; i++)
	{
		int diff = abs(num[i] - num[i - 1]);
		if (i != 1) gcdv = (gcdv > diff) ? gcd(gcdv, diff) : gcd(diff, gcdv);
		else gcdv = diff;
	}

	for (int i = 1; i <= sqrt(gcdv); i++)
	{
		if (gcdv % i == 0)
		{
			divisor.push_back(i);
			if (gcdv / i != i) divisor.push_back(gcdv / i);
		}
	}
	sort(divisor.begin(), divisor.end());

	size = divisor.size();
	for (int i = 1; i < size; i++)
		printf("%d ", divisor[i]);
	return 0;
}