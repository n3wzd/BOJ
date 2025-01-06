#include <iostream>
using namespace std;

int N, M;
int F[200001][19];
const int logM = 19;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) cin >> F[i][0];

	for (int k = 1; k < logM; k++)
		for (int i = 1; i <= N; i++)
			F[i][k] = F[F[i][k - 1]][k - 1];

	cin >> M;
	while (M--) {
		int n, x;
		cin >> n >> x;

		int k = logM - 1;
		while (k >= 0) {
			if (n & (1 << k)) x = F[x][k];
			k--;
		}
		cout << x << "\n";
	}
	return 0;
}
