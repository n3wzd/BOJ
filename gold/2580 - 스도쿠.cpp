#include <iostream>
using namespace std;

int sudoku[9][9] = { 0, };
bool isSubmit = false;

void Print()
{
	if (isSubmit) return;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << sudoku[i][j] << " ";
		cout << endl;
	}
	isSubmit = true;
}

void Answer(int posX, int posY)
{
	int x = posX, y = posY;

	while (y < 9)
	{
		if (sudoku[y][x] == 0)
		{
			// input number in (posX, posY)
			bool mask[10] = { 0, }; // 1 = exist, 0 = none, index = number(1-9)
			int sqX = x / 3 * 3, sqY = y / 3 * 3;
			bool mark = false;

			for (int xi = 0; xi < 9; xi++) // horizontal
				mask[sudoku[y][xi]] = 1;
			for (int yi = 0; yi < 9; yi++) // vertical
				mask[sudoku[yi][x]] = 1;
			for (int dy = 0; dy < 3; dy++) // square
				for (int dx = 0; dx < 3; dx++)
					mask[sudoku[sqY + dy][sqX + dx]] = 1;

			for (int i = 1; i <= 9; i++)
			{
				if (!mask[i]) // success - move to next state
				{
					sudoku[y][x] = i;
					Answer(x, y);
					if (isSubmit) return; // print only one answer
				}
			}
			sudoku[y][x] = 0;
			return; // fail - wrong answer! return to previous state
		}

		x++;
		if (x >= 9)
		{
			x = 0;
			y++;
		}
	}

	Print(); // final answer
}

int main()
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> sudoku[i][j];

	Answer(0, 0);
	return 0;
}
