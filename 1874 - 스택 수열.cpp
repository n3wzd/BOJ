#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int numList[100001];

int main()
{
	stack<int> stk;
	vector<char> vec;
	int n, cnt = 1;
	bool ok = true;
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &numList[i]);

	stk.push(cnt++);
	vec.push_back('+');

	for (int i = 0; i < n; i++)
	{
		int num = numList[i];

		if (stk.empty())
		{
			stk.push(cnt++);
			vec.push_back('+');
		}
		while (stk.top() < num)
		{
			stk.push(cnt++);
			vec.push_back('+');
		}
		if (cnt > n + 1)
		{
			ok = false;
			break;
		}

		while (!stk.empty())
		{
			if (stk.top() == num)
				break;
			stk.pop();
			vec.push_back('-');
		}

		if (stk.empty())
		{
			ok = false;
			break;
		}
		else
		{
			stk.pop();
			vec.push_back('-');
		}
	}

	if (ok)
	{
		int size = vec.size();
		for (int i = 0; i < size; i++)
			printf("%c\n", vec[i]);
	}
	else printf("NO\n");

	return 0;
}