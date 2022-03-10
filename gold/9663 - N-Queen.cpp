#include <iostream>
using namespace std;

int n;
int queen[15] = { 0, }; // index - y, value - x
int cases = 0;

void Queen(int y)
{
	if (y == n)
	{
		cases++;
		return;
	}

	bool board[15] = { 0, }; // 0 = safe, 1 = danger
	for (int i = 0; i < y; i++)
	{
		int x = queen[i];
		int leftDiagX = x - (y - i);
		int rightDiagX = x + (y - i);

		board[x] = 1;
		if (leftDiagX >= 0) board[leftDiagX] = 1;
		if (rightDiagX < n) board[rightDiagX] = 1;
	}

	for (int x = 0; x < n; x++)
	{
		if (!board[x])
		{
			queen[y] = x;
			Queen(y + 1);
		}
	}
}

int main()
{
	cin >> n;
	Queen(0);
	cout << cases << endl;
	return 0;
}