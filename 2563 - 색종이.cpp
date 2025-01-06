#include <iostream>
using namespace std;
const int SIZE = 102;
int arr[SIZE][SIZE];

int main() {
	int N, bx, by, sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> bx >> by;
		for (int x = 0; x < 10; x++)
			for (int y = 0; y < 10; y++)
				arr[by + y][bx + x] = 1;
	}
	for (int x = 0; x < SIZE; x++)
		for (int y = 0; y < SIZE; y++)
			sum += arr[y][x];
	cout << sum;
	return 0;
}
