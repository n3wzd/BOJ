#include <iostream>
using namespace std;

int main()
{
	int n, res = 0;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		string str;
		bool flag[26] = { 0, }; // character flag (1 - met, 0 - not met)
		int len;
		bool ok = true;

		cin >> str;
		len = str.length();

		for (int j = 0; j < len; j++)
		{
			if (j == 0) flag[str[0] - 97] = 1;
			else
			{
				if (str[j] != str[j - 1]) // don't consider consecutive one
				{
					if (flag[str[j] - 97])
					{
						ok = false;
						break;
					}
					flag[str[j] - 97] = 1;
				}
			}
		}
		if (ok) res++;
	}
	cout << res;
	return 0;
}