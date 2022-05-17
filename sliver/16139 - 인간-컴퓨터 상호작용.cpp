#include <iostream>
using namespace std;

string str;
int K;
int sum[200002][26];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str >> K;
	for (int i = 1; i <= str.size(); i++)
		for(int c = 0; c < 26; c++)
			sum[i][c] = sum[i - 1][c] + ((str[i - 1] - 'a' == c) ? 1 : 0);

	for (int i = 0; i < K; i++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		cout << sum[b + 1][c - 'a'] - sum[a][c - 'a'] << "\n";
	}
	return 0;
}
