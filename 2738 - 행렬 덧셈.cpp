#include <iostream>
using namespace std;
const int SIZE = 102;
int N, M;
int A[SIZE][SIZE], B[SIZE][SIZE];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> A[y][x];
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			cin >> B[y][x];
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++)
			cout << A[y][x] + B[y][x] << " ";
		cout << "\n";
	}
	return 0;
}