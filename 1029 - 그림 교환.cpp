#include <iostream>
using namespace std;

int N;
int cache[1 << 15][15][10];
int trade[15][15];

int DP(int list, int v, int cost)
{
	if (list == (1 << N) - 1) return 0;
	if (cache[list][v][cost] > 0) return cache[list][v][cost];

	cache[list][v][cost] = 1;
	for (int i = 0; i < N; i++)
		if (!(list & (1 << i)) && trade[v][i] >= cost && v != i)
			cache[list][v][cost] = max(cache[list][v][cost], 1 + DP(list | (1 << v), i, trade[v][i]));

	return cache[list][v][cost];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < N; j++)
			trade[i][j] = str[j] - '0';
	}
	cout << DP(0, 0, 0);
	return 0;
}
