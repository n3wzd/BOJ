#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	bool isAsc = 1, isDes = 1;
	for (int i = 1; i <= 8; i++) {
		int note;
		cin >> note;
		if (note != i) isAsc = 0;
		if (note != 9 - i) isDes = 0;
	}
	if (isAsc) cout << "ascending";
	else if (isDes) cout << "descending";
	else cout << "mixed";
	return 0;
}