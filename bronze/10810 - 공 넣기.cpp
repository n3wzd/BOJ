#include <iostream>
using namespace std;
int N, M, basket[102];

int main() {
	cin >> N >> M;
	while (M--) {
		int i, j, k;
		cin >> i >> j >> k;
		for (int x = i; x <= j; x++)
			basket[x] = k;
	}
	for (int x = 1; x <= N; x++)
		cout << basket[x] << " ";
	return 0;
}
