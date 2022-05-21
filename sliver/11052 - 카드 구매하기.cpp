#include <iostream>
using namespace std;

int N;
int card[1001];
int cache[1001][1001];
bool visited[1001][1001];

int DP(int n, int buy) {
	if (n < 1 || buy <= 0) return 0;
	if (visited[n][buy]) return cache[n][buy];

	for (int i = 0; i * n <= buy; i++)
		cache[n][buy] = max(cache[n][buy], DP(n - 1, buy - i * n) + i * card[n]);

	visited[n][buy] = 1;
	return cache[n][buy];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> card[i];
	cout << DP(N, N);
	return 0;
}
