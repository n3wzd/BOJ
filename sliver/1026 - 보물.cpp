#include <iostream>
#include <algorithm>
using namespace std;

int N, sum = 0;
int A[52];
int B[52];

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	for (int i = 0; i < N; i++) scanf("%d", &B[i]);
	sort(A, A + N);
	sort(B, B + N, cmp);
	for (int i = 0; i < N; i++) sum += A[i] * B[i];
	cout << sum << endl;
	return 0;
}