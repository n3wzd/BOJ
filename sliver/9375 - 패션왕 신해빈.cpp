#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
	int t;
	cin >> t;

	for (; t > 0; t--)
	{
		map<string, int> item;
		map<string, int>::iterator iter;
		int n, cases = 1;

		cin >> n;
		for (int i = 0; i < n; i++)
		{
			string str, gear;
			cin >> str >> gear;

			if (item.count(gear) != 0) item[gear] += 1;
			else item.insert({ gear , 1 });
		}

		for (iter = item.begin(); iter != item.end(); iter++)
			cases *= iter->second + 1;
		cout << cases - 1 << endl;
	}

	return 0;
}