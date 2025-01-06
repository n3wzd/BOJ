#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T, A, B;
	cin >> T;
	for (int i = 0; i < T; i++) {
		string s;
		cin >> s;
		A = s[0] - '0', B = s[2] - '0';
		cout << A + B << "\n";
	}
	return 0;
}
