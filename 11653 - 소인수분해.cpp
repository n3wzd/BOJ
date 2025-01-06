#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	while (n >= 2)
	{
		int d = 2;
		while (n % d != 0) d++;
		cout << d << endl;
		n /= d;
	}

	return 0;
}