#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	while (1)
	{
		stack<char> stk;
		string ps;
		getline(cin, ps);
		if (ps == ".")
			break;

		int len = ps.size();
		bool pass = true;
		for (int i = 0; i < len; i++)
		{
			if (ps[i] == '(') stk.push(ps[i]);
			else if (ps[i] == '[') stk.push(ps[i]);
			else if (ps[i] == ')')
			{
				if (!stk.empty())
				{
					if (stk.top() == '(') stk.pop();
					else pass = false;
				}
				else pass = false;
			}
			else if (ps[i] == ']')
			{
				if (!stk.empty())
				{
					if (stk.top() == '[') stk.pop();
					else pass = false;
				}
				else pass = false;
			}
		}

		if (!stk.empty()) pass = false;

		if (pass) cout << "yes" << endl;
		else cout << "no" << endl;
	}

	return 0;
}