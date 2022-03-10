#include <iostream>
using namespace std;

long long n, k;
long long arr[1000001];
long long range = 0;

bool Checker(long long value)
{
	long long choptree = 0;
	for (int i = 0; i < n; i++)
		choptree += (arr[i] > value) ? arr[i] - value : 0;
	return (choptree >= k);
}

long long BS()
{
	long long start = 0;
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
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		if (range < arr[i]) range = arr[i];
	}

	cout << BS() << endl;
	return 0;
}