#include <iostream>
#include <memory.h>
typedef long long ll;
using namespace std;
int N;
ll cache[31][31];

ll DP(int w, int h) {
	if (w < 0 || h < 0) return 0;
	if (w == 0 && h == 0) return 1;
	if (cache[w][h] > 0)
		return cache[w][h];

	cache[w][h] = DP(w - 1, h + 1) + DP(w, h - 1);
	return cache[w][h];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> N;
		if (N == 0) break;
		memset(cache, 0, sizeof(cache));
		cout << DP(N, 0) << "\n";
	}
	return 0;
}
