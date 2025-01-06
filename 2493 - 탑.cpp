#include <iostream>
#include <stack>
#include <utility>
using namespace std;

int N;
stack<pair<int, int>> larger;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		int tower;
		cin >> tower;

		while (!larger.empty())
		{
			if (larger.top().first < tower) larger.pop();
			else {
				cout <<larger.top().second << " ";
				break;
			}
		}
		if (larger.empty()) cout << 0 << " ";
		larger.push(make_pair(tower, i));
	}
	return 0;
}