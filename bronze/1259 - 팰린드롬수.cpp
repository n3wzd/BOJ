#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1)
	{
		string s;
		cin >> s;
		if (s == "0") return 0;

		int start = 0, end = s.size() - 1;
		bool palin = 1;
		while (start <= end)
			if (s[start++] != s[end--]) 
				palin = 0;
			
		if (palin) cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
}