#include <iostream>
#include <cmath>
using namespace std;

int N, M;
bool mine[751][751];
int V[751][751][2];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 1; y <= N; y++)
	{
		string row;
		cin >> row;
        for (int x = 1; x <= M; x++)
            mine[y][x] = row[x - 1] - '0';
	}
	int R = min(N, M), diamond = 0;
	if (R % 2 == 0) R--;
	R /= 2;

	for (int x = 1; x <= M; x++)
		for(int d = 0; d < 2; d++)
			V[1][x][d] = mine[1][x];

	for (int y = 2; y <= N; y++)
		for (int x = 1; x <= M; x++)
			for (int d = 0; d < 2; d++)
				V[y][x][d] = mine[y][x] + ((mine[y][x] != 0) ? V[y-1][x-1+(d*2)][d] : 0);

	for (int r = 0; r <= R; r++)
		for (int y = 1+r; y <= N-r; y++)
			for (int x = 1+r; x <= M-r; x++)
				if (V[y+r][x][0] >= r+1 && V[y+r][x][1] >= r+1 && V[y][x-r][1] >= r+1 && V[y][x+r][0] >= r+1)
					diamond = r+1;

	cout << diamond;
	return 0;
}
