#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int M, N;
	cin >> M >> N;
	cout << (N - 1) + (M - 1) + (N - 1) * (M - 1);
	return 0;
}
