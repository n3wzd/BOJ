#include <iostream>
using namespace std;

long long memoi[101] = { 0, };
long long result[10000];

long long Tri(long long n)
{
	if (memoi[n] != 0) return memoi[n];
	switch (n)
	{
	case 1:
	case 2:
	case 3: return 1;
	case 4:
	case 5: return 2;
	}

	memoi[n] = Tri(n - 1) + Tri(n - 5);
	return memoi[n];
}

int main()
{
	int tc;
	cin >> tc;

	for (int i = 0; i < tc; i++)
	{
		long long n;
		cin >> n;
		result[i] = Tri(n);
	}

	for (int i = 0; i < tc; i++)
		printf("%lld\n", result[i]);
}