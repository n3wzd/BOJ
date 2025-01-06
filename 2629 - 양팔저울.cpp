#include <iostream>
#include <cmath>
using namespace std;

int n, m;
int weight[2002];
bool cache[15002][32] = { 0, };
bool answer[40002] = { 0, };

void DP(int w, int i)
{
	if (i < 1)
	{
		answer[w] = 1;
		return;
	}
	if (cache[w][i]) return;

	cache[w][i] = 1;
	answer[w] = 1;
	DP(w + weight[i], i - 1);
	DP(abs(w - weight[i]), i - 1);
	DP(w, i - 1);
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%d", &weight[i]);
	DP(0, n);

	cin >> m;
	for (int i = 1; i <= m; i++)
	{
		int w;
		scanf("%d", &w);
		if(answer[w]) printf("Y ");
		else printf("N ");
	}
	
	return 0;
}