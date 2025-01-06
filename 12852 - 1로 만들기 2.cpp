#include <iostream>
#include <cmath>
using namespace std;

int cache[1000002] = { 0, };
int prev_pos[1000002];

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (i % 6 == 0)
		{
			cache[i] = 1 + min(cache[i / 3], min(cache[i / 2], cache[i - 1]));
			if (cache[i] == 1 + cache[i / 3]) prev_pos[i] = i / 3;
			else if (cache[i] == 1 + cache[i / 2]) prev_pos[i] = i / 2;
			else if (cache[i] == 1 + cache[i - 1]) prev_pos[i] = i - 1;
		}
		else if (i % 3 == 0)
		{
			cache[i] = 1 + min(cache[i / 3], cache[i - 1]);
			if (cache[i] == 1 + cache[i / 3]) prev_pos[i] = i / 3;
			else if (cache[i] == 1 + cache[i - 1]) prev_pos[i] = i - 1;
		}
		else if (i % 2 == 0)
		{
			cache[i] = 1 + min(cache[i / 2], cache[i - 1]);
			if (cache[i] == 1 + cache[i / 2]) prev_pos[i] = i / 2;
			else if (cache[i] == 1 + cache[i - 1]) prev_pos[i] = i - 1;
		}
		else
		{
			cache[i] = 1 + cache[i - 1];
			prev_pos[i] = i - 1;
		}
	}
	cout << cache[n] << endl;

	int chain = n;
	while (chain != 0)
	{
		printf("%d ", chain);
		chain = prev_pos[chain];
	}

	return 0;
}