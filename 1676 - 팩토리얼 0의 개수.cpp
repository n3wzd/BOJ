#include <iostream>
using namespace std;

int main()
{
	int num, five = 0;
	cin >> num;

	for (int i = 5; i <= num; i += 5)
	{
		int n = i / 5;
		five++;
		while (n % 5 == 0)
		{
			five++;
			n /= 5;
		}
	}

	cout << five << endl;
	return 0;
}