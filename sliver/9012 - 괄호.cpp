#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (; t > 0; t--)
	{
		string ps;
		cin >> ps;

		int len = ps.size();
		int cnt = 0;
		bool isVps = true;
		for (int i = len - 1; i >= 0; i--)
		{
			cnt += (ps[i] == ')') ? 1 : -1;
			if (cnt < 0)
			{
				isVps = false;
				break;
			}
		}
		if (cnt != 0)
			isVps = false;

		if (isVps) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}