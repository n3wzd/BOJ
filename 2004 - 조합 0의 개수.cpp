#include <iostream>
#include <cmath>
using namespace std;

long long FiveCounter(long long num)
{
	long long five = 0;
	for (long long m = 5; m <= num; m *= 5)
		five += (num / m);
	return five;
}

long long TwoCounter(long long num)
{
	long long two = 0;
	for (long long m = 2; m <= num; m *= 2)
		two += (num / m);
	return two;
}

int main()
{
	long long n, r, m;
	cin >> n >> r;
	m = n - r;

	cout << min(FiveCounter(n) - (FiveCounter(r) + FiveCounter(m)), TwoCounter(n) - (TwoCounter(r) + TwoCounter(m))) << endl;
	return 0;
}