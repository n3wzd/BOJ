#include <iostream>
#include <cmath>
using namespace std;

bool prime[1000002] = { 0, };

int main()
{
	long long min, max;
	cin >> min >> max;

	for (long long i = 2; i * i <= max; i++)
	{
		long long m = i * i;
		long long d = (min % m == 0) ? min : (min / m + 1) * m;

		while (d <= max)
		{
			prime[d - min] = 1;
			d += m;
		}
	}

	int sqrtNNsu = 0;
	for (long long i = 0; i <= max - min; i++)
		if (!prime[i]) sqrtNNsu++;

	cout << sqrtNNsu;
	return 0;
}