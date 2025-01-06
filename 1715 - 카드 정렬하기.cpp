#include <iostream>
#include <queue>
using namespace std;
int N, sum = 0, num, c1, c2;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		pq.push(num);
	}
	while (pq.size() > 1) {
		c1 = pq.top();
		pq.pop();
		c2 = pq.top();
		pq.pop();
		sum += c1 + c2;
		pq.push(c1 + c2);
	}
	cout << sum;
	return 0;
}
