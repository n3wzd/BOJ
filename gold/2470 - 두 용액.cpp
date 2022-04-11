#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int n, solution = 2000000001;
int water[100002];
int sol1, sol2;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &water[i]);
	sort(water, water + n);
	
	int start = 0, end = n - 1;
	while (start < end)
	{
		int sum = water[start] + water[end];
		if (abs(sum) < solution)
		{
			sol1 = (water[start] < water[end]) ? water[start] : water[end];
			sol2 = (water[start] >= water[end]) ? water[start] : water[end];
			solution = abs(sum);
		}
		else if (sum > 0) end--;
		else if (sum < 0) start++;
		else if (sum == 0) break;
	}

	cout << sol1 << " " << sol2 << endl;
	return 0;
}