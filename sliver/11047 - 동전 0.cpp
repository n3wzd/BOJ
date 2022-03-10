#include <iostream>
using namespace std;

int n, k;
int coin[10];
int result = 0;

int main()
{
	int sum = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> coin[i];

	for (int i = n - 1; i >= 0; i--)
	{
		while (sum + coin[i] <= k)
		{
			sum += coin[i];
			result++;
		}
	}

	cout << result << endl;
	return 0;
}