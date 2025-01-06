#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		q.push(i);

	int idx = 1;
	printf("<");
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (idx == m)
		{
			if(!q.empty()) printf("%d, ", v);
			else printf("%d>", v);
			idx = 1;
		}
		else
		{
			q.push(v);
			idx++;
		}
	}
	return 0;
}