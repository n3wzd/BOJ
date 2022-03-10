#include <iostream>
using namespace std;

int n;
int list[1002] = { 0, };
int cache[1002][2] = { 0, };
int cache_max = 0;

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &list[i]);

	for (int i = 1; i <= n; i++)
	{
		cache[i][0] = 1;
		for (int w = i - 1; w > 0; w--)
		{
			if (list[i] > list[w])
				cache[i][0] = max(cache[i][0], 1 + cache[w][0]);
		}
	}

	for (int i = n; i >= 1; i--)
	{
		cache[i][1] = 1;
		for (int w = i + 1; w <= n; w++)
		{
			if (list[i] > list[w])
				cache[i][1] = max(cache[i][1], 1 + cache[w][1]);
		}

		int bi = cache[i][0] + cache[i][1] - 1;
		if (cache_max < bi) cache_max = bi;
	}

	cout << cache_max << endl;
	return 0;
}