#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<int> pq;
int A, N, t = 0; ll ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> A;
	pq.push(A);
	for (int i = 1; i < N; i++) {
		cin >> A;
		int r = pq.top() + (++t);
		if (A <= r) {
			ans += r - A;
			pq.push(A - t);
			pq.pop();
		}
		pq.push(A - t);
	}
	cout << ans;
	return 0;
}
