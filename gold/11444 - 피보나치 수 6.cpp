#include <iostream>
using namespace std;

long long n, p = 1000000007;
long long matA[2][2] = { 1, 1, 1, 0 };
long long matBuf[2][2] = { 1, 0, 0, 1 };

long long ModMul(long long n1, long long n2)
{
	return ((n1 % p) * (n2 % p)) % p;
}

long long ModAdd(long long n1, long long n2)
{
	return ((n1 % p) + (n2 % p)) % p;
}

void MatMul1()
{
	long long matR[6][6] = { 0, };

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			for (int w = 0; w < 2; w++)
				matR[y][x] = ModAdd(matR[y][x], ModMul(matA[y][w], matA[w][x]));

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			matA[y][x] = matR[y][x];
}

void MatMul2()
{
	long long matR[6][6] = { 0, };

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			for (int w = 0; w < 2; w++)
				matR[y][x] = ModAdd(matR[y][x], ModMul(matA[y][w], matBuf[w][x]));

	for (int y = 0; y < 2; y++)
		for (int x = 0; x < 2; x++)
			matBuf[y][x] = matR[y][x];
}

int main()
{
	cin >> n;
	n--;

	while (n > 1)
	{
		if (n % 2 != 0) MatMul2();
		MatMul1();
		n /= 2;
	}
	MatMul2();

	cout << matBuf[0][0] << endl << endl;
	return 0;
}