#include <iostream>
using namespace std;
int arr[] = { 1, 1, 2, 2, 2, 8 };

int main() {
	int N = 6, num;
	for (int i = 0; i < N; i++) {
		cin >> num;
		cout << arr[i] - num << " ";
	}
	return 0;
}
