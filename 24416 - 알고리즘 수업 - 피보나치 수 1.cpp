#include <iostream>
using namespace std;
int fib[42] = { 1, 1, 0 };

int main() {
	int N;
	cin >> N;
	for (int i = 2; i < N; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	cout << fib[N - 1] << " " << N - 2;
	return 0;
}
