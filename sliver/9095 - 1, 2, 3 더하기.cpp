#include <iostream>
using namespace std;

int main()
{
	int N, T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		int cache[12] = { 1, 1, 2 };
		for (int n = 3; n <= N; n++)
			cache[n] = cache[n - 1] + cache[n - 2] + cache[n - 3];
		cout << cache[N] << "\n";
	}
	return 0;
}
