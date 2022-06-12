#include <iostream>
#include <cmath>
using namespace std;
long long N, n;

int main() {
	cin >> N;
	n = sqrt(N * 2);
	while (n * n + n > N * 2) n--;
	cout << n;
	return 0;
}
