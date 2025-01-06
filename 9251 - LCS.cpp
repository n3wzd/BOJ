#include <iostream>
#include <cmath>
using namespace std;

string str1, str2;
int LCS[1002][1002] = { 0, };

int main()
{
	cin >> str1 >> str2;
	int len1 = str1.length();
	int len2 = str2.length();

	for (int i = 1; i <= len1; i++)
	{
		for (int j = 1; j <= len2; j++)
		{
			if (str1[i - 1] == str2[j - 1]) LCS[i][j] = 1 + LCS[i - 1][j - 1];
			else LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}
	cout << LCS[len1][len2] << endl;
	return 0;
}