#include <iostream>
using namespace std;

int main()
{
	int n, b5, b3;
	bool ok = false;
	cin >> n;

	b5 = n / 5;
	while (b5 >= 0)
	{
		int rem = n - (b5 * 5);

		if (rem % 3 == 0)
		{
			b3 = rem / 3;
			ok = true;
			break;
		}
		b5--;
	}
	
	if(ok) cout << b5 + b3 << endl;
	else cout << -1 << endl;

	return 0;
}