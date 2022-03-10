#include <iostream>
#include <queue>
using namespace std;

int main()
{
	queue<int> q;
	int n, k;
	bool first = true;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		q.push(i);

	printf("<");
	while (!q.empty())
	{
		for (int i = 0; i < k - 1; i++)
		{
			q.push(q.front());
			q.pop();
		}

		if (first) first = false;
		else printf(", ");
		printf("%d", q.front());
		q.pop();
	}
	printf(">");

	return 0;
}