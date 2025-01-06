#include <iostream>
using namespace std;

int N, M, num;
int sum[100002];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> num;
		sum[i] = num + sum[i - 1];
	}
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a-1] << "\n";
	}
	return 0;
}
