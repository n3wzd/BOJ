#include <iostream>
#include <cmath>
using namespace std;

class Paint
{
public:
	int c[3];
};

int memoi[1000][3] = { 0, };
int home_cnt = 0;
Paint paint[1000];

int DP(int idx, int color)
{
	int c1, c2;
	if (color == 0) c1 = 1, c2 = 2;
	else if (color == 1) c1 = 0, c2 = 2;
	else c1 = 0, c2 = 1;

	int costA = paint[idx].c[color], costB = paint[idx].c[color];
	if (idx < home_cnt)
	{
		costA += (memoi[idx + 1][c1] != 0) ? memoi[idx + 1][c1] : DP(idx + 1, c1);
		costB += (memoi[idx + 1][c2] != 0) ? memoi[idx + 1][c2] : DP(idx + 1, c2);
	}
	memoi[idx][color] = min(costA, costB);
	return memoi[idx][color];
}

int main()
{
	cin >> home_cnt;
	for (int i = 0; i < home_cnt; i++)
		cin >> paint[i].c[0] >> paint[i].c[1] >> paint[i].c[2];

	cout << min(DP(0, 0), min(DP(0, 1), DP(0, 2))) << endl;
}