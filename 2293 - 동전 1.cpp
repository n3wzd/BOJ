#include <iostream>
using namespace std;

int n, k;
int coin[101];
int cache[10001][2] = { 0, }; // 인덱스 - 누적 돈, 값 - 경우의 수

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	for (int i = 0; i < n; i++)
	{
		int w = i % 2;

		for (int money = 1; money <= k; money++)
		{
			int cases = cache[money][(w + 1) % 2];
			if (money - coin[i] > 0)
				cases += cache[money - coin[i]][w];
			else if (money - coin[i] == 0)
				cases++;

			cache[money][w] = cases;
		}
	}

	printf("%d\n", cache[k][(n - 1) % 2]);
	return 0;
}