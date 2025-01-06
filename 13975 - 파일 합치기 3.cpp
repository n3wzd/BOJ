#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		int n;
		priority_queue<long long, vector<long long>, greater<long long>> min_heap;

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int page;
			scanf("%d", &page);
			min_heap.push(page);
		}

		long long cost = 0;
		while (min_heap.size() > 1)
		{
			long long temp = min_heap.top();
			min_heap.pop();
			temp += min_heap.top();
			min_heap.pop();

			cost += temp;
			min_heap.push(temp);
		}

		cout << cost << endl;
	}

	return 0;
}