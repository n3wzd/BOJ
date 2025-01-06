#include <iostream>
using namespace std;
const int SIZE = 100002;
int A[SIZE * 2];

string MakePalin(string str) {
	int len = str.size();
	string S;
	for (int i = 0; i < len; i++) {
		S += "#";
		S += str[i];
	}
	S += "#";
	return S;
}

void Manachers(string S) {
	int maxR = 0, cen = 0, N = S.size();
	for (int i = 0; i < N; i++) {
		if (maxR - i >= 0 && 2 * cen - i >= 0)
			A[i] = min(A[2 * cen - i], maxR - i);

		while (i - (A[i] + 1) >= 0 && i + A[i] + 1 < N && S[i - (A[i] + 1)] == S[i + A[i] + 1])
			A[i]++;

		if (maxR < i + A[i]) {
			maxR = i + A[i];
			cen = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string input, s;
	cin >> input;
	s = MakePalin(input);
	Manachers(s);

	int len = s.size(), pal = 1;
	for (int i = 0; i < len; i++)
		pal = max(pal, A[i]);
	cout << pal;
	return 0;
}
