#include <iostream>
using namespace std;

int n;
int list[1000002] = { -1000000001, 0, };
int cache[1000002] = { 0, 0, }; // value - last index of LIS, index - length of LIS 
int cache_size = 0;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &list[i]);

	for (int i = 1; i <= n; i++)
	{
		int start = 1;
		int end = cache_size;
		int mid = 0;

		if (list[cache[cache_size]] < list[i])
		{
			cache_size++;
			cache[cache_size] = i;
		}
		else
		{
			while (start < end) // lower_bound
			{
				mid = (start + end) / 2;
				if (list[cache[mid]] >= list[i]) end = mid;
				else start = mid + 1;
			}
			cache[end] = i;
		}
	}

	printf("%d\n", cache_size);
	return 0;
}