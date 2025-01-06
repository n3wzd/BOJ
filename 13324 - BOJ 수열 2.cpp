#include <iostream>
#include <queue>
using namespace std;
priority_queue<int> pq;
int A, N, t = 0, B[1000002];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> A;
	pq.push(A); B[0] = A;
	for (int i = 1; i < N; i++) {
		cin >> A;
		int r = pq.top() + (++t);
		if (A <= r) {
			pq.push(A - t);
			pq.pop();
		}
		pq.push(A - t);
		B[i] = pq.top();
	}
	for (int i = N - 2; i >= 0; i--)
		B[i] = min(B[i], B[i + 1]);
	for (int i = 0; i < N; i++)
		cout << B[i] + i << "\n";
	return 0;
}
