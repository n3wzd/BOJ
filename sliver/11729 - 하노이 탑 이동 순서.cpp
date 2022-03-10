#include <iostream>
#include <cmath>
using namespace std;

void Hanoi(int n, int start, int end)
{
	if (n == 1)
	{
		printf("%d %d\n", start, end);
		return;
	}

	bool filter[4] = { 0, };
	int mid;
	filter[start] = 1;
	filter[end] = 1;
	for (int i = 1; i <= 3; i++)
		if (filter[i] == 0)
			mid = i;

	Hanoi(n - 1, start, mid);
	printf("%d %d\n", start, end);
	Hanoi(n - 1, mid, end);
}

int main()
{
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1 << endl;
	Hanoi(n, 1, 3);
	return 0;
}