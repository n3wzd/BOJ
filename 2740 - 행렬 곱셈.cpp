#include <iostream>
#include <cmath>
using namespace std;

int n, m, k;
int matA[101][101];
int matB[101][101];
int matR[101][101] = { 0, };

int main()
{
	cin >> n >> m;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < m; x++)
			cin >> matA[y][x];
	cin >> m >> k;
	for (int y = 0; y < m; y++)
		for (int x = 0; x < k; x++)
			cin >> matB[y][x];

	for (int y = 0; y < n; y++)
		for (int x = 0; x < k; x++)
			for (int w = 0; w < m; w++)
				matR[y][x] += matA[y][w] * matB[w][x];

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < k; x++)
			cout << matR[y][x] << " ";
		cout << endl;
	}

	return 0;
}