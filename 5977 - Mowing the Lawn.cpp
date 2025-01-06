#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
int N, K, cow;
ll ps, cache;
struct Node { ll val; int id; };
deque<Node> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> cow;
		ps += cow;
		if (!dq.empty())
			if (n - (K + 1) >= dq.front().id)
				dq.pop_front();

		ll val = -ps + cache;
		while (!dq.empty()) {
			if (dq.back().val > val)
				break;
			dq.pop_back();
		}
		dq.push_back({ val, n });
		cache = (n - K > 0) ? ps + dq.front().val : ps;
	}
	cout << cache;
	return 0;
}