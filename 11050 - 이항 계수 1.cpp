#include <iostream>
using namespace std;

int Factorial(int n)
{
	return (n > 1) ? n * Factorial(n - 1) : 1;
}

int main()
{
	int n, k;
	cin >> n >> k;
	cout << Factorial(n) / (Factorial(k) * Factorial(n - k)) << endl;
	return 0;
}