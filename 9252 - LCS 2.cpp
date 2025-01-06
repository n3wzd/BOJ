#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

string str1, str2;
int LCS[1002][1002] = { 0, };
int path[1002][1002] = { 0, };

int main()
{
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1])
			{
				LCS[i][j] = 1 + LCS[i - 1][j - 1];
				path[i][j] = 3;
			}
			else
			{
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
				if(LCS[i][j] == LCS[i - 1][j]) path[i][j] = 2;
				else path[i][j] = 1;
			}
		}
	}
	cout << LCS[len1][len2] << endl;

	int y = len1, x = len2;
	stack<int> chain;
	while (y > 0 && x > 0)
	{
		if (path[y][x] == 1) x--;
		else if (path[y][x] == 2) y--;
		else
		{
			chain.push(y - 1);
			x--, y--;
		}
	}
	while (!chain.empty())
	{
		printf("%c", str1[chain.top()]);
		chain.pop();
	}

	return 0;
}