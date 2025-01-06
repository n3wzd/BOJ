#include <iostream>
using namespace std;

int main()
{
	int n, x = 0, dx = 6, res = 1;
	cin >> n;
	while (n > x + 1)
	{
		x += dx;
		dx += 6;
		res++;
	}

	cout << res << endl;
	return 0;
}