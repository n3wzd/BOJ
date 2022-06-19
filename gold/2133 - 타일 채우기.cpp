#include <iostream>
using namespace std;
int N, cache[31] = { 1, 0, 3, };

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 4; i <= N; i += 2) {
		cache[i] = 3 * cache[i - 2];
		for(int b = 4; i - b >= 0; b += 2)
			cache[i] += 2 * cache[i - b];
	}
	cout << cache[N];
	return 0;
}
