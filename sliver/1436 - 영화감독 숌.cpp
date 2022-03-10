#include <iostream>
using namespace std;

int main()
{
	int n, result, number = 666;
	cin >> n;

	while (1)
	{
		int six = 0;
		for (int i = number; i > 0; i /= 10)
		{
			if (i % 10 == 6) six++;
			else
			{
				if (six >= 3) break;
				six = 0;
			}
		}

		if (six >= 3)
		{
			n--;
			if (n == 0)
			{
				result = number;
				break;
			}
		}
		number++;
	}

	cout << result << endl;
	return 0;
}