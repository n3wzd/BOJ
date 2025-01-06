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
		int num;
		cin >> num;
		if (num == 0) stk.pop();
		else stk.push(num);
	}

	int sum = 0;
	while (!stk.empty())
	{
		sum += stk.top();
		stk.pop();
	}
	cout << sum << endl;

	return 0;
}