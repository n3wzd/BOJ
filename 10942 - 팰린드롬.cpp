#include <iostream>
using namespace std;

int n, m;
int list[2002];
bool cache[2002][2002] = { 0, };
bool cache_ck[2002][2002] = { 0, };

bool DP(int start, int end)
{
	if (end <= start) return 1;
	if (cache_ck[start][end]) return cache[start][end];

	cache[start][end] = (list[start] == list[end]) && DP(start + 1, end - 1);
	cache_ck[start][end] = 1;
	return cache[start][end];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &list[i]);
	
	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int start, end;
		scanf("%d%d", &start, &end);
		printf("%d\n", DP(start, end));
	}
	
	return 0;
}