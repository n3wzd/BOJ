#include <iostream>
using namespace std;

int paper[129][129];
int w = 0, b = 0;

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
		if (color == 0) w++;
		else b++;
	}
	else
	{
		Divide(n / 2, bx, by);
		Divide(n / 2, bx + n / 2, by);
		Divide(n / 2, bx, by + n / 2);
		Divide(n / 2, bx + n / 2, by + n / 2);
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
	cout << w << endl;
	cout << b << endl;
	return 0;
}