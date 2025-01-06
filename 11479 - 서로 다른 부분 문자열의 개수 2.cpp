#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int SIZE = 1000005;
string str;
int b, g[SIZE], tg[SIZE], SA[SIZE];
int r[SIZE], LCP[SIZE];

bool cmp(int x, int y) {
	if (g[x] == g[y])
		return g[x + b] < g[y + b];
	return g[x] < g[y];
}

void MakeSA() {
	b = 1;
	int n = str.size();
	for (int i = 0; i < n; i++) {
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	while (b <= n) {
		g[n] = -1;
		sort(SA, SA + n, cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(SA[i - 1], SA[i]))
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			else
				tg[SA[i]] = tg[SA[i - 1]];
		}
		for (int i = 0; i < n; i++)
			g[i] = tg[i];

		b *= 2;
	}
}

void MakeLCP() {
	int n = str.size();
	for (int i = 0; i < n; i++)
		r[SA[i]] = i;
	
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = r[i];
		if (k > 0) {
			int j = SA[k - 1];
			while (str[j + len] == str[i + len])
				len++;
			LCP[k] = len;
			if (len > 0)
				len--;
		}
	}
}

void Print() {
	int n = str.size();
	ll cnt = 0;
	for (int i = 0; i < n; i++)
		cnt += (n - SA[i]) - LCP[i];
	cout << cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	MakeSA();
	MakeLCP();
	Print();
	return 0;
}
