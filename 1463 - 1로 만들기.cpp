#include <iostream>
#include <cmath>
using namespace std;

int cache[1000002] = { 0, };

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
	{
		if (i % 6 == 0) cache[i] = 1 + min(cache[i / 3], min(cache[i / 2], cache[i - 1]));
		else if (i % 3 == 0) cache[i] = 1 + min(cache[i / 3], cache[i - 1]);
		else if (i % 2 == 0) cache[i] = 1 + min(cache[i / 2], cache[i - 1]);
		else cache[i] = 1 + cache[i - 1];
	}

	cout << cache[n] << endl;
	return 0;
}