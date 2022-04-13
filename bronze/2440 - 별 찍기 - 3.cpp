#include <iostream>
using namespace std;

int N;

int main()
{
	cin >> N;
	while (N--)
	{
		for (int i = N; i >= 0; i--)
			printf("*");
		printf("\n");
	}
	return 0;
}