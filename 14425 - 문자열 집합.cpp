#include <iostream>
#include <set>
using namespace std;

int N, M, cnt = 0;
set<string> imset;
string str;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	while (N--)
	{
		cin >> str;
		imset.insert(str);
	}
	while (M--)
	{
		cin >> str;
		if (imset.find(str) != imset.end()) cnt++;
	}
	cout << cnt;
	return 0;
}
