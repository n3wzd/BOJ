#include <iostream>
using namespace std;

int num1[10001];
int num2[10001];

int main()
{
	int len = 0;
	while (1)
	{
		cin >> num1[len] >> num2[len];
		if (num1[len] == 0 && num2[len] == 0)
			break;
		len++;
	}

	for (int i = 0; i < len; i++)
	{
		if (num2[i] % num1[i] == 0) cout << "factor" << endl;
		else if (num1[i] % num2[i] == 0) cout << "multiple" << endl;
		else cout << "neither" << endl;
	}
	return 0;
}