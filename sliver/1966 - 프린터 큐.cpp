#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		queue<int> ready, buf;
		int priority[101];
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> priority[i];
			ready.push(i);
		}

		int cnt = 1;
		while (cnt <= n)
		{
			buf.push(ready.front());
			ready.pop();

			while (!ready.empty())
			{
				if (priority[buf.front()] < priority[ready.front()])
				{
					while (!buf.empty()) // buf -> ready
					{
						ready.push(buf.front());
						buf.pop();
					}
				}

				buf.push(ready.front());
				ready.pop();
			}

			if (buf.front() == k) break;
			buf.pop();
			cnt++;

			while (!buf.empty()) // buf -> ready
			{
				ready.push(buf.front());
				buf.pop();
			}
		}

		cout << cnt << endl;
	}

	return 0;
}