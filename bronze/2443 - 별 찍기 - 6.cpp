#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++) printf(" ");
		for (int j = (n-i-1) * 2; j >= 0; j--) printf("*");
		printf("\n");
	}
	return 0;
}