#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int coin[21];
int cache[21][10001];
bool visited[21][10001];

int DP(int c, int money)
{
	if (money == 0) return 1;
	if (money < 0 || c <= 0) return 0;
	if (visited[c][money]) return cache[c][money];

	int m = money;
	while (m >= 0)
	{
		cache[c][money] += DP(c - 1, m);
		m -= coin[c];
	}

	visited[c][money] = 1;
	return cache[c][money];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; i++)
			cin >> coin[i];
		cin >> M;

		for (int c = 0; c <= N; c++) {
			for (int m = 0; m <= M; m++){
				cache[c][m] = 0;
				visited[c][m] = 0;
			}
		}

		cout << DP(N, M) << "\n";
	}
	return 0;
}
