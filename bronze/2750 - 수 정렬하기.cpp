#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1002];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + n);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}