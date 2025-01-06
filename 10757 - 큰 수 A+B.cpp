#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	cin >> s1 >> s2;

	string base = (s1.size() > s2.size()) ? s1 : s2;
	string adder = (s1.size() <= s2.size()) ? s1 : s2;

	int carry = 0;
	int ai = adder.size() - 1, bi = base.size() - 1;
	while (ai >= 0)
	{
		int a = (int)adder[ai] - 48;
		int b = (int)base[bi] - 48;
		int sum = a + b + carry;

		carry = (sum > 9) ? 1 : 0;
		sum %= 10;
		base[bi] = (char)(sum + 48);
		ai--, bi--;
	}

	while (bi >= 0 && carry == 1)
	{
		int b = (int)base[bi] - 48;
		int sum = b + carry;

		carry = (sum > 9) ? 1 : 0;
		sum %= 10;
		base[bi] = (char)(sum + 48);
		bi--;
	}

	if (carry == 1)
		base = "1" + base;

	cout << base << endl;
	return 0;
}