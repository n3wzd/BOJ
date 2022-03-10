#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> max_heap;
priority_queue<int, vector<int>, greater<int>> min_heap;

int main()
{
	int t;
	scanf("%d", &t);

	for (; t > 0; t--)
	{
		int num;
		scanf("%d", &num);

		if (max_heap.empty())
		{
			max_heap.push(num);
			printf("%d\n", num);
			continue;
		}

		int center = max_heap.top();
		if (center >= num) max_heap.push(num);
		else min_heap.push(num);

		int max_size = max_heap.size();
		int min_size = min_heap.size();
		if (max_size < min_size)
		{
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		else if (max_size > min_size + 1)
		{
			min_heap.push(max_heap.top());
			max_heap.pop();
		}

		center = max_heap.top();
		printf("%d\n", center);
	}

	return 0;
}