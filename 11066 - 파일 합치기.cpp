#include <iostream>
#include <cmath>
using namespace std;
const int INT_MAXV = 2147483647;

int n;
int page[501];
int fsize[501][501];
int rsum[501][501];

int GetSum(int start, int end)
{
	if (rsum[start][end] != 0) return rsum[start][end];

	rsum[start][end] = 0;
	for (int i = start; i <= end; i++)
		rsum[start][end] += page[i];
	return rsum[start][end];
}

int DP(int start, int end)
{
	if (end == start) return 0;
	if (fsize[start][end] != 0) return fsize[start][end];

	int min_size = INT_MAXV;
	int range_sum = GetSum(start, end);
	for (int d = start; d <= end - 1; d++)
		min_size = min(min_size, range_sum + DP(start, d) + DP(d + 1, end));

	fsize[start][end] = min_size;
	return fsize[start][end];
}

int main()
{
	int t;
	cin >> t;
	for (; t > 0; t--)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &page[i]);
			for (int j = 0; j < n; j++)
			{
				fsize[i][j] = 0;
				rsum[i][j] = 0;
			}
		}

		printf("%d\n", DP(0, n - 1));
	}

	return 0;
}