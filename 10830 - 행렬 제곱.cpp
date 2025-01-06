#include <iostream>
#include <cmath>
using namespace std;

int n, p = 1000;
long long b;
int matA[6][6] = { 0, };
int matBuf[6][6] = { 0, };

int ModMul(int n1, int n2)
{
	return ((n1 % p) * (n2 % p)) % p;
}

int ModAdd(int n1, int n2)
{
	return ((n1 % p) + (n2 % p)) % p;
}

void MatMul1()
{
	int matR[6][6] = { 0, };

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			for (int w = 0; w < n; w++)
				matR[y][x] = ModAdd(matR[y][x], ModMul(matA[y][w], matA[w][x]));

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			matA[y][x] = matR[y][x];
}

void MatMul2()
{
	int matR[6][6] = { 0, };

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			for (int w = 0; w < n; w++)
				matR[y][x] = ModAdd(matR[y][x], ModMul(matA[y][w], matBuf[w][x]));

	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			matBuf[y][x] = matR[y][x];
}

int main()
{
	cin >> n >> b;
	for (int y = 0; y < n; y++)
		for (int x = 0; x < n; x++)
			cin >> matA[y][x];

	for (int y = 0; y < n; y++)
		matBuf[y][y] = 1;

	while (b > 1)
	{
		if (b % 2 != 0) MatMul2();
		MatMul1();
		b /= 2;
	}
	MatMul2();

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			cout << matBuf[y][x] << " ";
		cout << endl;
	}

	return 0;
}