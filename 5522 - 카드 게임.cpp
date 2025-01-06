#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int sum = 0, num;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		sum += num;
	}
	cout << sum;
	return 0;
}
