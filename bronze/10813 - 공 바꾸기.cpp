#include <iostream>
using namespace std;
int N, M, a, b, tmp, arr[102];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		arr[i] = i;
	while (M--) {
		cin >> a >> b;
		tmp = arr[a];
		arr[a] = arr[b];
		arr[b] = tmp;
	}
	for (int i = 1; i <= N; i++)
		cout << arr[i] << " ";
	return 0;
}
