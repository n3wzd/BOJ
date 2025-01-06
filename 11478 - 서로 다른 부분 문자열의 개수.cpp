#include <iostream>
#include <set>
using namespace std;

set<string> imset;
string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> str;

	int len = str.size();
	for (int i = 0; i < len; i++)
	{
		string buffer = "";
		for (int j = i; j < len; j++)
		{
			buffer += str[j];
			imset.insert(buffer);
		}
	}
	cout << imset.size();
	return 0;
}