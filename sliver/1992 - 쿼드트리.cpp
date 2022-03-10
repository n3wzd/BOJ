#include <iostream>
using namespace std;

char board[65][65];

void Quad(int n, int bx, int by)
{
	char color = board[by][bx];
	bool pass = true;

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			if (color != board[by + y][bx + x])
				pass = false;

	if (pass)
	{
		cout << color;
	}
	else
	{
		cout << "(";
		Quad(n / 2, bx, by);
		Quad(n / 2, bx + n / 2, by);
		Quad(n / 2, bx, by + n / 2);
		Quad(n / 2, bx + n / 2, by + n / 2);
		cout << ")";
	}
}

int main()
{
	int n;
	cin >> n;
	for (int y = 0; y < n; y++)
	{
		string line;
		cin >> line;
		for (int x = 0; x < n; x++)
			board[y][x] = line[x];
	}

	Quad(n, 0, 0);
	return 0;
}