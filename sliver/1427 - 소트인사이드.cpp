#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[12];

bool cmp(int a, int b) {
	return a > b;
}

int main()
{
	string s;
	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++)
		arr[i] = (int)s[i] - 48;
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d", arr[i]);
	return 0;
}