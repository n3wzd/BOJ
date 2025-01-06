#include <iostream>
#include <cmath>
using namespace std;

int cost_max = 0;
int mem[102];
int cost[102];
int cache[10002][102] = { 0, };

int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		scanf("%d", &mem[i]);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &cost[i]);
		cost_max += cost[i];
	}

	for (int c = 0; c <= cost_max; c++)
	{
		for (int n = 1; n <= N; n++)
		{
			if(c - cost[n] >= 0)
				cache[c][n] = max(cache[c - cost[n]][n - 1] + mem[n], cache[c][n - 1]);
			else
				cache[c][n] = cache[c][n - 1];

			if (cache[c][n] >= M)
			{
				cout << c << endl;
				return 0;
			}
		}
	}
	return 0;
}