#include <iostream>
#include <stack>
using namespace std;

int numList[1000001];
int ohBigsu[1000001];

int main()
{
	stack<int> stk;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &numList[i]);

		while (!stk.empty())
		{
			if (numList[stk.top()] < numList[i])
			{
				ohBigsu[stk.top()] = numList[i];
				stk.pop();
			}
			else break;
		}

		stk.push(i);
	}

	while (!stk.empty())
	{
		ohBigsu[stk.top()] = -1;
		stk.pop();
	}

	for (int i = 0; i < n; i++)
		printf("%d ", ohBigsu[i]);

	return 0;
}