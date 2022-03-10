#include <iostream>
using namespace std;

int main()
{
	int n, res = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int num;
		bool ok = true;
		cin >> num;
		if (num <= 1) continue;

		for (int j = 2; j <= num / 2; j++)
		{
			if (num % j == 0)
			{
				ok = false;
				break;
			}
		}
		if (ok) res++;
	}

	cout << res;
	return 0;
}