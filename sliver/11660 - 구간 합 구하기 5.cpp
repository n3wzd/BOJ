#include <iostream>
using namespace std;

int N, K, num;
int sum[1025][1025];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int x = 1; x <= N; x++) {
		for (int y = 1; y <= N; y++) {
			cin >> num;
			sum[y][x] = num + sum[y - 1][x] + sum[y][x - 1] - sum[y - 1][x - 1];
		}
	}
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << sum[y2][x2] - sum[y1 - 1][x2] - sum[y2][x1 - 1] + sum[y1 - 1][x1 - 1] << "\n";
	}
	return 0;
}
