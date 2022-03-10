#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int main()
{
	queue<int> q, ready;
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		q.push(i);
	for (int i = 1; i <= m; i++)
	{
		int a;
		cin >> a;
		ready.push(a);
	}

	int cnt = 0, sum = 0;
	while (!ready.empty())
	{
		if (q.front() == ready.front())
		{
			int s = q.size();
			sum += min(cnt, s - cnt);
			cnt = 0;
			q.pop();
			ready.pop();
			continue;
		}

		q.push(q.front());
		q.pop();
		cnt++;
	}

	cout << sum << endl;
	return 0;
}