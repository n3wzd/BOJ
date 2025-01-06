#include <iostream>
#include <vector>
using namespace std;
const int SIZE = 1000002;
int A[SIZE * 2];
vector<int> S;

void Manachers() {
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
	int N, M;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		S.push_back(0);
		S.push_back(num);
	}
	S.push_back(0);
	Manachers();

	cin >> M;
	for (int i = 0; i < M; i++) {
		int lo, hi;
		cin >> lo >> hi;
		lo--, hi--;
		if (A[(lo + hi) + 1] > hi - lo) cout << 1 << "\n";
		else cout << 0 << "\n";
	}
	return 0;
}
