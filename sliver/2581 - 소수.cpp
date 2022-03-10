#include <iostream>
#include <cmath>
using namespace std;
bool prime[1000000] = { 0, }; // 0 - prime number

int main()
{
	int n, m;
	cin >> n >> m;
	int num_limit = sqrt(m);
	int min = 0, sum = 0;

	for (int i = 2; i <= num_limit; i++)
		if (!prime[i])
			for (int j = i * 2; j <= m; j += i)
				prime[j] = 1;
		
	if (n < 2) n = 2;
	for (int i = n; i <= m; i++)
	{
		if (!prime[i])
		{
			if (min == 0) min = i;
			sum += i;
		}
	}

	if(min != 0) printf("%d\n%d\n", sum, min);
	else printf("-1\n");
	return 0;
}