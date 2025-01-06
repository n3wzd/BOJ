#include <iostream>
#include <algorithm>
using namespace std;
int N, K, arr[1002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);
	cout << arr[N - K];
	return 0;
}
