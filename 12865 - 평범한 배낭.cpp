#include <iostream>
#include <cmath>
using namespace std;

int n, k;
int weight[102];
int value[102];
int cache[102][100002] = { 0, };
int cache_ck[102][100002] = { 0, };

int DP(int i, int w)
{
	if (w > k) return -1;
	if (i == 0) return 0;
	if (cache_ck[i][w]) return cache[i][w];

	int A = DP(i - 1, w + weight[i]);
	int B = DP(i - 1, w);
	if (A != -1) A += value[i];

	cache[i][w] = max(A, B);
	cache_ck[i][w] = true;
	return cache[i][w];
}

int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> weight[i] >> value[i];

	printf("%d\n", DP(n, 0));
	return 0;
}