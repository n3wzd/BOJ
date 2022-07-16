#include <iostream>
#include <queue>
using namespace std;
struct Node { int num, id; };
int N, L, num;
deque<Node> dq;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> num;
		if (!dq.empty())
			if (i - L >= dq.front().id)
				dq.pop_front();

		while (!dq.empty()) {
			if (dq.back().num < num)
				break;
			dq.pop_back();
		}
		dq.push_back({ num, i });
		cout << dq.front().num << " ";
	}
	return 0;
}