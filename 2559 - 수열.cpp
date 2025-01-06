#include <iostream>
using namespace std;

int N, K, num, res = -10000001;
int sum[100002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		sum[i] = num + sum[i - 1];
	}
	for (int i = 1; i <= N - (K - 1); i++)
		res = max(res, sum[i + (K - 1)] - sum[i - 1]);
	cout << res << "\n";
	return 0;
}
