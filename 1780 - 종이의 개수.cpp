#include <iostream>
using namespace std;

int paper[2188][2188];
int cnt[3] = { 0, };

void Divide(int n, int bx, int by)
{
	int color = paper[by][bx];
	bool pass = true;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			if (color != paper[by + y][bx + x])
				pass = false;

	if (pass)
	{
		cnt[color + 1]++;
	}
	else
	{
		int p = n / 3;
		for (int y = 0; y < 3; y++)
			for (int x = 0; x < 3; x++)
				Divide(p, bx + p * x, by + p * y);
	}
}

int main()
{
	int n;
	cin >> n;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> paper[y][x];

	Divide(n, 0, 0);
	for (int i = 0; i < 3; i++)
		cout << cnt[i] << endl;
	return 0;
}