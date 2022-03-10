#include <iostream>
using namespace std;

const int p = 15746;

int ModAdd(int a, int b)
{
	return ((a % p) + (b % p)) % p;
}

int main()
{
	int n;
	int cases = 1, A = 1, B = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cases = ModAdd(A, B);
		B = A;
		A = cases;
	}
	cout << cases << endl;

	return 0;
}