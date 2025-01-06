#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string s;
	cin >> s;

	int lo = 0, hi = s.size() - 1;
	bool isPalin = 1, allEq = 1;
	while (lo <= hi) {
		isPalin &= s[lo] == s[hi];
		allEq &= (s[0] == s[lo]) && (s[0] == s[hi]);
		lo++, hi--;
	}
	if (allEq) cout << -1;
	else if (isPalin) cout << s.size() - 1;
	else cout << s.size();
	return 0;
}
