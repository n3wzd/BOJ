#include <iostream>
using namespace std;
string str;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;
	int len = str.size();
	for (int i = 0; i < len; i++)
		cout << i << "\n";
	return 0;
}
