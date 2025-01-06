#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, sum = 0;
vector<int> parr, marr;
bool hasZero = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		if (n > 0) parr.push_back(n);
		if (n < 0) marr.push_back(n);
		if (n == 0) hasZero = 1;
	}
	sort(parr.begin(), parr.end(), greater<int>());
	sort(marr.begin(), marr.end());

	int len = parr.size();
	for (int i = 0; i < len - 1; i += 2) {
		if(parr[i + 1] == 1) sum += parr[i] + parr[i + 1];
		else sum += parr[i] * parr[i + 1];
	}
	if (len % 2 != 0)
		sum += parr[len - 1];

	len = marr.size();
	for (int i = 0; i < len - 1; i += 2)
		sum += marr[i] * marr[i + 1];
	if (len % 2 != 0 && !hasZero) 
		sum += marr[len - 1];

	cout << sum;
	return 0;
}
