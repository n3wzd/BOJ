#include <iostream>
#include <stack>
using namespace std;

int n;
int list[1000002] = { -1000000001, 0, };
int cache[1000002] = { 0, }; // value - last index of LIS, index - length of LIS 
int cache_size = 0;
int LIS[1000002];

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
			LIS[i] = cache[cache_size - 1];
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
			LIS[i] = cache[end - 1];
		}
	}

	printf("%d\n", cache_size);

	int idx = cache[cache_size];
	stack<int> stk;
	while (idx != 0)
	{
		stk.push(list[idx]);
		idx = LIS[idx];
	}
	while (!stk.empty())
	{
		printf("%d ", stk.top());
		stk.pop();
	}

	return 0;
}