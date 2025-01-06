#include <iostream>
using namespace std;
int N, K, paper[100002];

bool Scan(int v) {
	int sum = 0, group = 0;
	for (int i = 0; i < N; i++) {
		sum += paper[i];
		if (sum >= v) {
			group++;
			sum = 0;
		}
	}
	return K <= group;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> paper[i];

	int ran = N * 20;
	int lo = 0, hi = ran;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		if (Scan(ran - mid)) hi = mid;
		else lo = mid + 1;
	}
	cout << ran - lo;
	return 0;
}
