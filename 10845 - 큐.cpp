#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	queue<int> q;
	int T, n;
	cin >> T;
	while(T--) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			cin >> n;
			q.push(n);
		}
		else if (cmd == "pop") {
			if (q.empty()) cout << "-1\n";
			else {
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (cmd == "size")	cout << q.size() << "\n";
		else if (cmd == "empty") cout << q.empty() << "\n";
		else if (cmd == "front") {
			if (q.empty()) cout << "-1\n";
			else cout << q.front() << "\n";
		}
		else if (cmd == "back") {
			if (q.empty()) cout << "-1\n";
			else cout << q.back() << "\n";
		}
	}
	return 0;
}
