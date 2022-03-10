#include <iostream>
#include <algorithm>
using namespace std;

long long n, c;
long long arr[200001];
long long range = 0;

bool Checker(long long value)
{
	long long rem = c - 1;
	int cur = 0;
	for (int i = 1; i < n; i++)
	{
		if (arr[i] - arr[cur] >= value)
		{
			cur = i;
			rem--;
			if (rem == 0) break;
		}
	}
	return (rem == 0);
}

long long BS()
{
	long long start = 1;
	long long end = range;
	long long mid = 0;

	while (start < end)
	{
		mid = ((start + end) % 2 == 0) ? (start + end) / 2 : (start + end) / 2 + 1;
		if (Checker(mid)) start = mid;
		else end = mid - 1;
	}

	return end;
}

int main()
{
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	range = arr[n - 1] - arr[0];

	cout << BS() << endl;
	return 0;
}