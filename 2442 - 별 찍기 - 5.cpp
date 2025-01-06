#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int w = 0; w < N + i; w++)
			cout << (w <= N - (i + 2) ? " " : "*");
		cout << "\n";
	}
	return 0;
}
