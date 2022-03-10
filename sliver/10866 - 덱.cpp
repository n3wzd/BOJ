#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int main()
{
	deque<int> q;
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		char cmd[15];
		scanf("%s", cmd);

		if (strcmp(cmd, "push_front") == 0)
		{
			int i;
			scanf("%d", &i);
			q.push_front(i);
		}
		else if (strcmp(cmd, "push_back") == 0)
		{
			int i;
			scanf("%d", &i);
			q.push_back(i);
		}
		else if (strcmp(cmd, "pop_front") == 0)
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.front());
				q.pop_front();
			}
		}
		else if (strcmp(cmd, "pop_back") == 0)
		{
			if (q.empty()) printf("-1\n");
			else
			{
				printf("%d\n", q.back());
				q.pop_back();
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