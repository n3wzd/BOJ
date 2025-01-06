#include <iostream>
#include <cmath>
using namespace std;

int N;
int cache[1001][3][3];
int paint[1001][3];
const int INF = 1000001;

int DP(int h, int color, int first_color)
{
	if (cache[h][color][first_color] > 0) return cache[h][color][first_color];
	if (h == 0) return (first_color == color) ? INF : paint[h][color];
	return cache[h][color][first_color] = paint[h][color] +
		min(DP(h - 1, (color + 1) % 3, first_color), DP(h - 1, (color + 2) % 3, first_color));
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int c = 0; c < 3; c++)
			cin >> paint[i][c];
	cout << min(DP(N-1, 0, 0), min(DP(N - 1, 1, 1), DP(N - 1, 2, 2)));
	return 0;
}
