#include <iostream>
using namespace std;
const int SIZE = 5002, INF = 1 << 30;
int Q, N, file, S[SIZE];
int cache[SIZE][SIZE], K[SIZE][SIZE];

void Solve() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> file;
		S[i] = S[i - 1] + file;
		cache[i - 1][i] = 0;
		K[i - 1][i] = i;
	}

	for (int w = 2; w <= N; w++) {
		for (int i = 0; i + w <= N; i++) {
			int j = i + w;
			cache[i][j] = INF;
			for (int k = K[i][j - 1]; k <= K[i + 1][j]; k++) {
				int v = cache[i][k] + cache[k][j] + S[j] - S[i];
				if (v < cache[i][j]) {
					cache[i][j] = v;
					K[i][j] = k;
				}
			}
		}
	}
	cout << cache[0][N] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Q;
	while (Q--)
		Solve();
	return 0;
}
