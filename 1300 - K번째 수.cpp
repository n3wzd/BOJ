#include <iostream>
#include <cmath>
using namespace std;

int n, k;

int BS()
{
	int start = 1;
	int end = (int)min((long long)1000000000, (long long)n * n);
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;

		int sum = 0, range = sqrt(mid);
		for (int i = 1; i <= range; i++)
			sum += (min((mid / i), n) - (i - 1)) * 2 - 1;

		if (k <= sum) end = mid;
		else start = mid + 1;
	}

	return end;
}

int main()
{
	cin >> n >> k;
	cout << BS() << endl;
	return 0;
}