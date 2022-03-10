#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> stk;
	int t;
	cin >> t;

	for (; t > 0; t--)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int num;
			cin >> num;
			stk.push(num);
		}
		else if (cmd == "pop")
		{
			if (stk.empty()) cout << -1 << endl;
			else
			{
				cout << stk.top() << endl;
				stk.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << stk.size() << endl;
		}
		else if (cmd == "empty")
		{
			cout << stk.empty() << endl;
		}
		else if (cmd == "top")
		{
			if (stk.empty()) cout << -1 << endl;
			else cout << stk.top() << endl;
		}
	}

	return 0;
}