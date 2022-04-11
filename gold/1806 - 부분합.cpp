#include <iostream>
#include <cmath>
using namespace std;

int N, S, sum = 0, min_len = 100002;
int arr[100002];

int main()
{
	cin >> N >> S;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
		sum += arr[i];
	}
	if (sum < S)
	{
		cout << 0 << endl;
		return 0;
	}
	
	int start = 0, end = N - 1;
	while (end < N && start <= end)
	{
		if (sum >= S)
		{
			min_len = end - start + 1;
			sum -= arr[end];
			end--;
		}
		else if (sum < S)
		{
			sum -= arr[start];
			start++;
			end++;
			sum += arr[end];
		}
	}

	cout << min_len << endl;
	return 0;
}