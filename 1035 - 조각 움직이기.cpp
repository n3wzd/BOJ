#include <iostream>
using namespace std;

int N = 0, res = 9999;
int board[7][7];
int cenx, ceny;

int GetMinDist(int px, int py)
{
	int cost = 99;
	for (int y = 1; y <= 5; y++)
		for (int x = 1; x <= 5; x++)
			if (board[y][x] == 2)
				cost = min(cost, abs(x - px) + abs(y - py) - 1);
	return cost;
}

void Simul(int cost, bool first)
{
	bool isEnd = 1;
	for (int y = 1; y <= 5; y++)
	{
		for (int x = 1; x <= 5; x++)
		{
			if (board[y][x] != 1) continue;
			board[y][x] = 0;
			isEnd = 0;

			if (first)
			{
				if (board[ceny][cenx] != 0)
				{
					board[y][x] = 1;
					continue;
				}
				board[ceny][cenx] = 2;
				Simul(abs(cenx - x) + abs(ceny - y), 0);
				board[ceny][cenx] = 0;
				board[y][x] = 1;
				continue;
			}

			int mvcost = GetMinDist(x, y);
			int tx[7], ty[7];
			int t_size = 0;
			for (int ny = 1; ny <= 5; ny++)
			{
				for (int nx = 1; nx <= 5; nx++)
				{
					if (mvcost != abs(x - nx) + abs(y - ny)) continue;
					if (board[ny][nx] == 1) continue;
					if (!(board[ny+1][nx] == 2 || board[ny-1][nx] == 2 || board[ny][nx+1] == 2 || board[ny][nx-1] == 2)) continue;
					tx[t_size] = nx, ty[t_size++] = ny;
				}	
			}

			for (int t = 0; t < t_size; t++)
			{
				board[ty[t]][tx[t]] = 2;
				Simul(cost + mvcost, 0);
				board[ty[t]][tx[t]] = 0;
			}
			board[y][x] = 1;
		}
	}
	if (isEnd) res = min(res, cost);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int y = 1; y <= 5; y++)
	{
		string str;
		cin >> str;
		for (int x = 1; x <= 5; x++)
			board[y][x] = (str[x-1] == '*') ? 1 : 0;
	}
	for (ceny = 1; ceny <= 5; ceny++)
		for (cenx = 1; cenx <= 5; cenx++)
			Simul(0, 1);
	cout << res;
	return 0;
}