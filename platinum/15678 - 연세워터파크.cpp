#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
int N, D;
ll dary, score = -1e9;
ll cache[100002];
struct Node { ll val; int id; };
deque<Node> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> D;
	for (int n = 1; n <= N; n++) {
		cin >> dary;
		if (!dq.empty())
			if (n - (D + 1) >= dq.front().id)
				dq.pop_front();

		ll prev = (!dq.empty() ? dq.front().val : 0);
		cache[n] = dary + (prev > 0 ? prev : 0);
		score = max(score, cache[n]);

		while (!dq.empty()) {
			if (dq.back().val > cache[n])
				break;
			dq.pop_back();
		}
		dq.push_back({ cache[n], n });
	}
	cout << score;
	return 0;
}