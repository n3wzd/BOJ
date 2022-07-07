#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZE = 1000001;
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
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	Z(s.c_str());

	int N, pos, size = s.size();
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> pos;
		cout << z[size - pos] << "\n";
	}
	return 0;
}
