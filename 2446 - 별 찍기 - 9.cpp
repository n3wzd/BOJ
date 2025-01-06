#include <iostream>
using namespace std;

int n;

void Print(int start, int end)
{
	for (int i = 0; i < n * 2 - 1; i++)
	{
		if (i >= start && i < end) printf("*");
		else if (i < start) printf(" ");
	}
	printf("\n");
}

void Print1(int start, int end)
{
	if (start > end) return;
	Print(start, end);
	Print1(start + 1, end - 1);
}

void Print2(int start, int end)
{
	if (end - start > n * 2 - 1) return;
	Print(start, end);
	Print2(start - 1, end + 1);
}

int main()
{
	cin >> n;
	Print1(0, n * 2 - 1);
	Print2(n - 2, n + 1);
	return 0;
}
