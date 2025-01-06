#include <iostream>
using namespace std;
const int CARD_NUM = 3;

int main()
{
	int n, m, max = -1;
	int p[3] = {0, 1, 2};
	int card[100];
	cin >> n >> m;
	if (n < 3) n = 3;
	for (int i = 0; i < n; i++) cin >> card[i];

	while (1)
	{
		int sum = card[p[0]] + card[p[1]] + card[p[2]];
		if (max < sum && sum <= m) max = sum;

		if (p[0] == n - 3) break;
		else if (p[1] == n - 2) { p[0]++; p[1] = p[0] + 1; p[2] = p[1] + 1; }
		else if (p[2] == n - 1) { p[1]++; p[2] = p[1] + 1; }
		else p[2]++;
	}
	cout << max;

	return 0;
}