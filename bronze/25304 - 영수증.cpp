#include <iostream>
using namespace std;
int sum1, N, a, b, sum2 = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> sum1 >> N;
	while(N--) {
		cin >> a >> b;
		sum2 += a * b;
	}
	cout << (sum1 == sum2 ? "Yes" : "No");
	return 0;
}
