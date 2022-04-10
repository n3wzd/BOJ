#include <iostream>
#include <cmath>
using namespace std;

int S, N, K, R1, R2, C1, C2;

int Fractal(int x, int y, int s)
{
	if (s == 0) return 0;

	int d = pow(N, s - 1);
	int ran = d * K;
	int mg = (N - K) / 2 * d;

	if (x >= mg && x < mg + ran && y >= mg && y < mg + ran) return 1;
	else return Fractal(x % d, y % d, s - 1);
}

int main()
{
	cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
	int p = pow(N, S);

	for (int y = R1; y <= R2; y++)
	{
		for (int x = C1; x <= C2; x++)
			printf("%d", Fractal(x, y, S));
		printf("\n");
	}
	return 0;
}