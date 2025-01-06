#include <iostream>
#include <cmath>
using namespace std;
bool prime[1000000] = { 0, }; // 0 - prime number

int main()
{
	int n, m;
	cin >> n >> m;
	int num_limit = sqrt(m);

	for (int i = 2; i <= num_limit; i++)
		if (!prime[i])
			for (int j = i * 2; j <= m; j += i)
				prime[j] = 1;
		
	if (n < 2) n = 2;
	for (int i = n; i <= m; i++)
		if (!prime[i])
			printf("%d\n", i);

	/*for (int i = 2; i <= m; i++)
	{
		int num = i;
		bool ok = true;
		int num_limit = sqrt(num);
		int prime_limit = prime.size();
		if (num <= 1) continue;

		for (int j = 0; j < prime_limit; j++)
		{
			if (prime[j] > num_limit) break;

			if (num % prime[j] == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			if (i >= n) cout << num << endl;
			prime.push_back(num);
		}
	}*/

	/*for (int i = n; i <= m; i++)
	{
		int num = i;
		bool ok = true;
		int num_limit = num / 2;
		if (num <= 1) continue;

		for (int j = 2; j <= num_limit; j++)
		{
			if (num % j == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			// cout << num << endl;
		}
	}*/

	return 0;
}