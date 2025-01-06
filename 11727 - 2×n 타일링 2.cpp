#include <iostream>
using namespace std;

const int p = 10007;
int cache[1002] = { 1, 1, 0 };

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= n; i++)
		cache[i] = (cache[i - 1] % p + (2 * cache[i - 2] % p) % p) % p;

	cout << cache[n] << endl;
	return 0;
}