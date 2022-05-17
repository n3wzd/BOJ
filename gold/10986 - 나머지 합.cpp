#include <iostream>
typedef long long ll;
using namespace std;

int N, M, num;
int sum[1000002];
ll cnt[1002] = { 1 };
ll res;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		sum[i] = ((num % M) + sum[i - 1]) % M;
		cnt[sum[i]]++;
	}
	for (int i = 0; i <= 1000; i++)
		res += (cnt[i] - 1) * (cnt[i]) / 2;
	cout << res;
	return 0;
}
