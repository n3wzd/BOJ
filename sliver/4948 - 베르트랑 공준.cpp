#include <iostream>
#include <cmath>
using namespace std;
bool prime[1000000] = { 0, }; // 0 - prime number
int result[100000];

int main()
{
	int len = 0;

	while (1)
	{
		int n, m, count = 0;
		cin >> n;
		if (n == 0) break;

		m = 2 * n;
		int num_limit = sqrt(m);
		if (num_limit < 2) num_limit = 2;

		for (int i = 2; i <= num_limit; i++)
			if (!prime[i])
				for (int j = i * 2; j <= m; j += i)
					prime[j] = 1;

		for (int i = n+1; i <= m; i++)
			if (!prime[i])
				count++;

		result[len] = count;
		len++;
	}
	
	for(int i = 0; i < len; i++)
		printf("%d\n", result[i]);

	return 0;
}