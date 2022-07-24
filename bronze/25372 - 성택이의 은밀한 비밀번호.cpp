#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		if (str.size() >= 6 && str.size() <= 9)
			cout << "yes\n";
		else
			cout << "no\n";
	}
	return 0;
}
