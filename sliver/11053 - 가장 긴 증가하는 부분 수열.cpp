#include <iostream>
using namespace std;

int n;
int list[1002] = { 0, };
int cache[1002] = { 0, };
int cache_point[1002] = { 0, };

int DP(int i)
{
	if (cache[i] != 0) return cache[i];

	cache[i] = 1;
	for (int w = i + 1; w <= n; w++)
	{
		if (list[w] > list[i])
		{
			int a = cache[i];
			int b = 1 + DP(w);
			if (b > a)
			{
				cache[i] = b;
				cache_point[i] = w;
			}
		}
	}
	return cache[i];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> list[i];

	cout << DP(0) - 1 << endl;

	/*int w = cache_point[0];
	while(w != 0)
	{
		cout << list[w] << " ";
		w = cache_point[w];
	}*/

	return 0;
}