#include <iostream>
using namespace std;
int N, K, L;
int num[21];
int cache[21][1 << 10][2];
bool visited[21][1 << 10][2];
const int INF = 10;

int DP(int p, int vst, int st)
{
	if (visited[p][vst][st]) return cache[p][vst][st];

	int cnt = 0;
	for (int i = 0; i < 10; i++)
		cnt += (vst & (1 << i)) ? 1 : 0;
	if (p == L)	return (cnt == K) ? -1 : INF;
	else if (cnt > K) return INF;

	cache[p][vst][st] = INF;
	int start = (st) ? num[p] : 0;
	for (int i = 9; i >= start; i--)
		if (DP(p + 1, (vst | (1 << i)), st && i == num[p]) != INF)
			cache[p][vst][st] = i;

	visited[p][vst][st] = 1;
	return cache[p][vst][st];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str >> K;
	L = str.size();
	for (int i = 0; i < L; i++) num[i] = str[i] - '0';

	if (L < K) { // greedy
		for (int i = 0; i < K; i++) {
			if (i == 0) cout << 1;
			else if (i == 1) cout << 0;
			else cout << i;
		}
	}
	else {
		int res = DP(0, 0, 1); // DP

		if (res != INF) { // DP trace
			int vst = 0, st = 1;
			for (int p = 0; p < L; p++) {
				res = cache[p][vst][st];
				cout << res;
				vst = (vst | (1 << res));
				st = (st && (res == num[p]));
			}
		}
		else { // greedy
			for (int i = 0; i < K; i++) {
				if (i == 0) cout << 1;
				else if (i == 1)
					for (int j = 0; j < L - (K - 2); j++)
						cout << 0;
				else cout << i;
			}
		}
	}
	return 0;
}
