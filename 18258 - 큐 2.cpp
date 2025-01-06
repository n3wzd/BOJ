#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main()
{
	queue<int> q;
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		char cmd[10];
		scanf("%s", cmd);

		if (strcmp(cmd, "push") == 0)
		{
			int i;
			scanf("%d", &i);
			q.push(i);
		}
		else if (strcmp(cmd, "pop") == 0)
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (strcmp(cmd, "size") == 0)
		{
			printf("%d\n", q.size());
		}
		else if (strcmp(cmd, "empty") == 0)
		{
			printf("%d\n", q.empty());
		}
		else if (strcmp(cmd, "front") == 0)
		{
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.front());
		}
		else if (strcmp(cmd, "back") == 0)
		{
			if (q.empty()) printf("-1\n");
			else printf("%d\n", q.back());
		}
	}
	return 0;
}