#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int SIZE = 100001;
int z[SIZE];

void Z(const char* s) {
	int L = 0, R = 0, n = strlen(s);
	for (int i = 1; i < n; i++) {
		if (i > R) {
			L = R = i;
			while (R < n && s[R - L] == s[R])
				R++;
			z[i] = R - L;
			R--;
		}
		else {
			int k = i - L;
			if (z[k] < R - i + 1)
				z[i] = z[k];
			else {
				L = i;
				while (R < n && s[R - L] == s[R])
					R++;
				z[i] = R - L;
				R--;
			}
		}
	}
	z[0] = n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, K;
	string s;
	cin >> N >> K >> s;
	Z(s.c_str());

	N = s.size();
	if (K >= N)
		cout << N;
	else {
		int ans = 0;
		for (int i = 1; i < N; i++) {
			if (z[i] == N - i) {
				if (2 * i >= N) {
					if (K >= i - z[i])
						ans = i;
				}
				else {
					if (K >= (i - (N % i)) % i)
						ans = i;
				}
			}
		}
		cout << ans;
	}
	return 0;
}
