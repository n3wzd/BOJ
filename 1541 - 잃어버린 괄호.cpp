#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	cin >> str;

	int len = str.size();
	int pos_prev = 0;
	int sum_cur = 0, sum_final = 0, sign = 1;

	for (int i = 0; i < len; i++)
	{
		if (str[i] == '+')
		{
			sum_cur += stoi(str.substr(pos_prev, i - pos_prev));
			pos_prev = i + 1;
		}
		else if (str[i] == '-')
		{
			sum_cur += stoi(str.substr(pos_prev, i - pos_prev));
			pos_prev = i + 1;
			sum_final += sum_cur * sign;

			sum_cur = 0;
			sign = -1;
		}
	}
	sum_cur += stoi(str.substr(pos_prev, len - pos_prev));
	sum_final += sum_cur * sign;

	cout << sum_final << endl;
	return 0;
}