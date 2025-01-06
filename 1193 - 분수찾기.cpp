#include <iostream>
using namespace std;

int main()
{
	int n, a = 1;
	cin >> n;
	while (1)
	{
		if (a % 2 == 0)
		{
			for (int b = 1; b <= a; b++)
			{
				if (--n == 0)
				{
					cout << b << "/" << a - b + 1 << endl;
					return 0;
				}
			}
		}
		else
		{
			for (int b = a; b >= 1; b--)
			{
				if (--n == 0)
				{
					cout << b << "/" << a - b + 1 << endl;
					return 0;
				}
			}
		}
		a++;
	}
}