#include <iostream>
#include <cmath>
using namespace std;

int N;
long long hist[100003];

long long DIV(int start, int end)
{
	if (start > end) return 0;
	if (start == end) return hist[end];
	int lmid = (start + end) / 2;
	int rmid = (start + end) / 2 + 1;
	long long min_height = min(hist[lmid], hist[rmid]);
	long long area = 0;

	while (1)
	{
		while (!(lmid == start || min_height > hist[lmid - 1]))
			lmid--;
		while (!(rmid == end || min_height > hist[rmid + 1]))
			rmid++;
		area = max(area, min_height * (rmid - lmid + 1));

		if (lmid != start && rmid != end) min_height = max(hist[lmid - 1], hist[rmid + 1]);
		else if (lmid != start) min_height = hist[lmid - 1];
		else if (rmid != end) min_height = hist[rmid + 1];
		else break;
	}
	
	return max(area, max(DIV(start, (start + end) / 2), DIV((start + end) / 2 + 1, end)));
}

int main()
{
	while (1)
	{
		scanf("%d", &N);
		if (N == 0) return 0;
		for (int i = 1; i <= N; i++)
			scanf("%lld", &hist[i]);
		printf("%lld\n", DIV(1, N));
	}
}