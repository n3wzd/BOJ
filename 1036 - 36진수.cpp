#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
using namespace std;

int N, K;
string nums[51];
pair<char, string> weight[37];

bool cmp(pair<int, string> a, pair<int, string> b) { 
	return (a.second.size() != b.second.size()) ? a.second.size() > b.second.size() : a.second > b.second;
}

int Converter(char c) { return (c >= 'A') ? c - 'A' + 10 : c - '0'; }
char Inverter(int n) { return (n >= 10) ? n - 10 + 'A' : n + '0'; }

string Adder(string s1, string s2) // s1.size >= s2.size
{
	if (s1.size() < s2.size()) // swap
	{
		string temp = s1;
		s1 = s2;
		s2 = temp;
	}

	int p1 = s1.size() - 1, p2 = s2.size() - 1;
	int sum, carry = 0;
	while(p2 >= 0)
	{
		sum = Converter(s1[p1]) + Converter(s2[p2]) + carry;
		if (sum >= 36)
		{
			sum -= 36;
			carry = 1;
		}
		else carry = 0;
		s1[p1] = Inverter(sum);
		p1--, p2--;
	}
	while (carry > 0)
	{
		if (p1 >= 0)
		{
			sum = Converter(s1[p1]) + carry;
			if (sum >= 36)
			{
				sum -= 36;
				carry = 1;
			}
			else carry = 0;
			s1[p1] = Inverter(sum);
			p1--;
		}
		else
		{
			string temp = "1";
			temp += s1;
			s1 = temp;
			carry = 0;
		}
	}
	return s1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 36; i++)
	{
		weight[i].first = Inverter(i);
		weight[i].second = "0";
	}

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> nums[i];
		int p = nums[i].size() - 1;
		string w = "0";
		while(p >= 0)
		{
			int c = Converter(nums[i][p]);
			w[0] = Inverter(35 - c);
			if(w[0] != '0')
				weight[c].second = Adder(weight[c].second, w);
			w[0] = '0', w += "0", p--;
		}
	}
	sort(weight, weight + 36, cmp);

	cin >> K;
	for (int i = 0; i < K; i++)
	{
		char rep = weight[i].first;
		for (int j = 0; j < N; j++)
		{
			int len = nums[j].size();
			for (int s = 0; s < len; s++)
				if (nums[j][s] == rep) nums[j][s] = 'Z';
		}
	}

	for (int i = 1; i < N; i++)
		nums[0] = Adder(nums[0], nums[i]);
	cout << nums[0];
	return 0;
}