#include <iostream>
#include <cmath>
using namespace std;

int n;
int stair[302] = { 0, };
int cache[302][3] = { 0, };

int DP(int i, int combo)
{
	if (i > n || combo > 1) return 0;
	if (i == n) return stair[i];
	if (cache[i][combo] != 0) return cache[i][combo];

	int next = max(DP(i + 1, combo + 1), DP(i + 2, 0));
	if (next == 0) return 0;

	cache[i][combo] = stair[i] + next;
	return cache[i][combo];
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> stair[i];

	cout << DP(0, -1) << endl;
	return 0;
}