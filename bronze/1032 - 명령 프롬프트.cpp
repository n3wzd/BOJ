#include <iostream>
using namespace std;

int N, fs;
string base;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> base;
	fs = base.size();
	for (int i = 1; i < N; i++)
	{
		string fi;
		cin >> fi;
		for (int w = 0; w < fs; w++)
			if (fi[w] != base[w] && base[w] != '?')
				base[w] = '?';
	}
	cout << base;
	return 0;
}
