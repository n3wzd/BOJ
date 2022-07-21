#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N, lo, hi, di[2] = { 1, -1 };
	cin >> N;
	lo = 1, hi = N * 2 - 2;
	for (int y = 0; y < N * 2; y++) {
		for (int x = 0; x < N * 2; x++)
			cout << ((x >= lo && x <= hi) ? " " : "*");
		lo += di[(y + 1) / N], hi -= di[(y + 1) / N];
		cout << "\n";
	}
	return 0;
}
