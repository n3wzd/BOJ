#include <iostream>
#include <cmath>
using namespace std;

bool prime[10002] = { 0, };

int main()
{
	int t = 0;
	scanf("%d", &t);
	for (; t > 0; t--)
	{
		int n;
		scanf("%d", &n);

		int sq = sqrt(n);
		for (int i = 2; i <= sq; i++)
		{
			int d = i * 2;
			while (d <= n)
			{
				prime[d] = 1;
				d += i;
			}
		}

		for (int i = n / 2; i >= 2; i--)
		{
			if (!prime[i] && !prime[n - i])
			{
				printf("%d %d\n", i, n - i);
				break;
			}
		}
	}

	return 0;
}