#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		deque<int> q;
		string cmd, arrs;
		int len;
		cin >> cmd >> len >> arrs;

		int arrs_len = arrs.size(), wd = 0;
		for (int i = 1; i < arrs_len; i++)
		{
			if ((arrs[i] == ',' || arrs[i] == ']') && wd > 0)
			{
				q.push_back(stoi(arrs.substr(i - wd, wd)));
				wd = 0;
			}
			else wd++;
		}

		bool dire = 1; // 1 - forward, 0 - reverse
		bool error = 0;
		int cmd_len = cmd.size();
		for (int i = 0; i < cmd_len; i++)
		{
			if (cmd[i] == 'R') dire = !dire;
			if (cmd[i] == 'D')
			{
				if (!q.empty())
				{
					if (dire) q.pop_front();
					else q.pop_back();
				}
				else
				{
					error = true;
					break;
				}
			}
		}

		if (!error)
		{
			int q_size = q.size();
			bool first = true;

			printf("[");
			while (!q.empty())
			{
				if (first) first = false;
				else printf(",");

				int num = 0;
				if (dire)
				{
					num = q.front();
					q.pop_front();
				}
				else
				{
					num = q.back();
					q.pop_back();
				}
				printf("%d", num);
			}
			printf("]\n");
		}
		else
			printf("error\n");
	}
	return 0;
}