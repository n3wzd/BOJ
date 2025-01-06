#include <iostream>
#include <string>
using namespace std;

int main()
{
	string n;
	int f;
	cin >> n >> f;

	int len = n.size();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			string n2 = n;
			n2[len - 1] = j + 48;
			n2[len - 2] = i + 48;

			int n3 = stoi(n2);
			if (n3 % f == 0)
			{
				cout << n2[len - 2] << n2[len - 1] << endl;
				return 0;
			}
		}
	}

	return 0;
}