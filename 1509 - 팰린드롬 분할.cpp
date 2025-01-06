#include <iostream>
using namespace std;
const int SIZE = 2505;
int N;
string S;
int group[SIZE] = { 1, };
bool palin[SIZE][SIZE];

void DP_Palin() {
	for (int lo = 0; lo < N; lo++)
		palin[lo][lo] = palin[lo + 1][lo] = 1;
	for (int w = 1; w < N; w++)
		for (int lo = 0, hi = w; hi < N; lo++, hi++)
			palin[lo][hi] = (S[lo] == S[hi]) && palin[lo + 1][hi - 1];
}

int DP_Group(int n) {
	if (group[n] > 0)
		return group[n];
	if (palin[0][n])
		return group[n] = 1;

	group[n] = n + 1;
	for (int bar = 1; bar <= n; bar++) {
		if(palin[bar][n])
			group[n] = min(group[n], DP_Group(bar - 1) + 1);
	}
	return group[n];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> S;
	N = S.size();
	DP_Palin();
	cout << DP_Group(N - 1);
	return 0;
}
