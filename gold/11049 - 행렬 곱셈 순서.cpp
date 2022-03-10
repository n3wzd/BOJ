#include <iostream>
#include <cmath>
using namespace std;
const long long INT_MAXV = 2147483647;

class Mat
{
public:
	long long x, y;
};

int n;
Mat mat[502];
long long matmul[502][502];

long long DP(int start, int end)
{
	if (end == start) return 0;
	if (matmul[start][end] != 0) return matmul[start][end];

	matmul[start][end] = INT_MAXV;
	for (int d = start; d <= end - 1; d++)
		matmul[start][end] = min(matmul[start][end], DP(start, d) + DP(d + 1, end) + (mat[start].x * mat[d + 1].x * mat[end].y));

	return matmul[start][end];
}

int main()
{
	scanf("%d", &n);
	for (long long i = 0; i < n; i++)
		scanf("%lld %lld", &mat[i].x, &mat[i].y);

	printf("%lld\n", DP(0, n - 1));
	return 0;
}