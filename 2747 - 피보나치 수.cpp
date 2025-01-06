#include <iostream>
using namespace std;

int DP[100] = { 0, 1 };

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++)
		DP[i] = DP[i - 1] + DP[i - 2];
	cout << DP[n];
	return 0;
}