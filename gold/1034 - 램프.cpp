#include <iostream>
#include <cmath>
using namespace std;

int N, M, K;
string board[52];
int max_bulb = 0;

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		cin >> board[y];
	cin >> K;

	for (int y = 0; y < N; y++)
	{
		int zero = 0;
		for (int x = 0; x < M; x++)
			if (board[y][x] == '0')
				zero++;

		if (zero <= K && zero % 2 == K % 2)
		{
			int cnt = 0;
			for (int y2 = 0; y2 < N; y2++)
				if (board[y] == board[y2])
					cnt++;
			max_bulb = max(max_bulb, cnt);
		}
	}
	cout << max_bulb << endl;
	return 0;
}