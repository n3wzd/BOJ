#include <iostream>
using namespace std;

int N;
int cache[1 << 20];
int work[20][20];
const int INF = 20 * 10000 + 1;

int DP(int list, int w)
{
	if (w == N) return 0;
	if (cache[list] > 0) return cache[list];

	cache[list] = INF;
	for (int i = 0; i < N; i++)
		if(!(list & (1 << i)))
			cache[list] = min(cache[list], DP(list | (1 << i), w + 1) + work[i][w]);
		
	return cache[list];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> work[i][j];

	cout << DP(0, 0);
	return 0;
}
