#include <iostream>
using namespace std;
int N, yes = 0, no = 0, test;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> test;
		if (test == 1) yes++;
		else no++;
	}
	if (yes > no) cout << "Junhee is cute!";
	else cout << "Junhee is not cute!";
	return 0;
}
