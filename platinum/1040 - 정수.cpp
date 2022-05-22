#include <iostream>
using namespace std;
int K, L;
int num[19];
int cache[19][1 << 11][2];
bool visited[19][1 << 11][2];
int INF = 11;

int DP(int p, int vst, int st)
{
	if (visited[p][vst][st]) return cache[p][vst][st];

	int cnt = 0;
	for (int i = 0; i < 10; i++)
		cnt += (vst & (1 << i)) ? 1 : 0;
	if (p == L) {
		if (cnt == K) return -1;
		else return INF;
	}
	else if (cnt > K)
		return INF;

	cache[p][vst][st] = INF;
	int start = (st) ? num[p] : 0;
	for (int i = 9; i >= start; i--) {
		int st2;
		if (st == 1 && (i == num[p])) st2 = 1;
		else st2 = 0;
		if (DP(p + 1, vst | (1 << i), st2) != INF)
			cache[p][vst][st] = i;
	}

	visited[p][vst][st] = 1;
	return cache[p][vst][st];
}

int main()
{
	// ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string str;
	cin >> str;
	cin >> K;
	L = str.size();
	for (int i = 0; i < L; i++) num[i] = str[i] - '0';

	if (L < K) { // greedy
		for (int i = 0; i < K; i++) {
			if (i == 0) cout << "1";
			else if (i == 1) cout << "0";
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
				vst = vst | (1 << res);
				if (st == 1 && (res == num[p])) st = 1;
				else st = 0;
			}
		}
		else { // greedy
			for (int i = 0; i < K; i++) {
				if (i == 0) cout << "1";
				else if (i == 1)
					for (int j = 0; j < L - (K - 2); j++)
						cout << "0";
				else cout << i;
			}
		}
	}
	cout << "\n";
	return 0;
}
