#include <iostream>
using namespace std;

int m, n;
int map[502][502] = { 0, };
int cache[502][502] = { 0, };
bool cache_ck[502][502] = { 0, };

int DP(int x, int y)
{
	if (x > n || y > m || x < 1 || y < 1) return 0;
	if (x == n && y == m) return 1;
	if (cache_ck[y][x]) return cache[y][x];

	if (map[y][x] > map[y][x + 1]) cache[y][x] += DP(x + 1, y);
	if (map[y][x] > map[y][x - 1]) cache[y][x] += DP(x - 1, y);
	if (map[y][x] > map[y + 1][x]) cache[y][x] += DP(x, y + 1);
	if (map[y][x] > map[y - 1][x]) cache[y][x] += DP(x, y - 1);
	cache_ck[y][x] = 1;
	return cache[y][x];
}

int main()
{
	cin >> m >> n;
	for (int y = 1; y <= m; y++)
		for (int x = 1; x <= n; x++)
			scanf("%d", &map[y][x]);

	cout << DP(1, 1) << endl;
	return 0;
}