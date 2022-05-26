#include <iostream>
#include <queue>
using namespace std;
string str;
int N, M;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	deque<char> left, right;
	cin >> str;
	N = str.size();
	for (int i = 0; i < N; i++)
		left.push_back(str[i]);

	cin >> M;
	while (M--) {
		char a, b;
		cin >> a;
		if (a == 'L') {
			if (!left.empty()) {
				right.push_front(left.back());
				left.pop_back();
			}
		}
		else if(a == 'D') {
			if (!right.empty()) {
				left.push_back(right.front());
				right.pop_front();
			}
		}
		else if (a == 'B') {
			if (!left.empty()) {
				left.pop_back();
			}
		}
		else if (a == 'P') {
			cin >> b;
			left.push_back(b);
		}
	}

	while (!left.empty()) {
		cout << left.front();
		left.pop_front();
	}
	while (!right.empty()) {
		cout << right.front();
		right.pop_front();
	}
	return 0;
}
