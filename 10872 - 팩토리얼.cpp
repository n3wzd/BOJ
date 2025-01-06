#include <iostream>
#include <cmath>
using namespace std;

int Fact(int n)
{
	if (n <= 1) return 1;
	return n * Fact(n - 1);
}

int main()
{
	int n;
	cin >> n;
	cout << Fact(n) << endl;
	return 0;
}