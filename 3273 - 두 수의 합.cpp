#include <iostream>
#include <algorithm>
using namespace std;

int n, x, cnt = 0;
int arr[100002];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	cin >> x;
	sort(arr, arr + n);
	
	int start = 0, end = n - 1;
	while (start < end)
	{
		int sum = arr[start] + arr[end];
		if (sum == x)
		{
			cnt++;
			start++;
		}
		else if (sum > x) end--;
		else if (sum < x) start++;
	}

	cout << cnt << endl;
	return 0;
}