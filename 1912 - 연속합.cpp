#include <iostream>
#include <cmath>
using namespace std;

int n;
int list[100002] = { 0, };
int sum = 0;
int maxValue = 0;

int main()
{
	int len;
	cin >> len;
	for (int i = 0; i < len; i++)
		scanf("%d", &list[i]);

	maxValue = list[0];
	for (int i = 0; i < len; i++)
	{
		sum += list[i];
		maxValue = max(maxValue, sum);
		if (sum <= 0) sum = 0;
	}

	cout << maxValue << endl;
	return 0;
}