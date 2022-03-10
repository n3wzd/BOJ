#include <iostream>
#include <algorithm>
using namespace std;

int list[500001];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &list[i]);
	sort(list, list + n);

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int goal;
		scanf("%d", &goal);
		printf("%d ", upper_bound(list, list + n, goal) - lower_bound(list, list + n, goal));
	}

	return 0;
}