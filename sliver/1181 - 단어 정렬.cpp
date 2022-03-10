#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool cmp(string a, string b){
	if (a.length() != b.length()) return a.length() < b.length();
	else return a < b;
}

int main()
{
	vector<string> arr;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		arr.push_back(s);
	}

	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	sort(arr.begin(), arr.end(), cmp);

	int len = arr.size();
	for (int i = 0; i < len; i++)
		cout << arr[i] << endl;

	return 0;
}