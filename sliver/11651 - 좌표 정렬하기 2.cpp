#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> arr[100002];

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	else return a.first < b.first;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d %d\n", arr[i].first, arr[i].second);
	return 0;
}