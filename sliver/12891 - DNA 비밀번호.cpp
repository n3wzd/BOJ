#include <iostream>
using namespace std;
int P, S, cap[4];
int pass = 0, cnt[4]; // a - 0, c - 1, g - 2, t - 3
string str;

int stoi(int i) {
	if (str[i] == 'A') return 0;
	if (str[i] == 'C') return 1;
	if (str[i] == 'G') return 2;
	else return 3;
}

void IsPass() {
	bool ok = 1;
	for (int d = 0; d < 4; d++)
		ok &= (cnt[d] >= cap[d]);
	if (ok) pass++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> P >> S >> str;
	for (int d = 0; d < 4; d++)
		cin >> cap[d];
	for (int i = 0; i < S; i++)
		cnt[stoi(i)]++;
	IsPass();

	for (int lo = 1; lo + S <= P; lo++) {
		cnt[stoi(lo - 1)]--;
		cnt[stoi(lo + S - 1)]++;
		IsPass();
	}
	cout << pass;
	return 0;
}
