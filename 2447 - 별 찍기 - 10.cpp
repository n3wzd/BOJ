#include <iostream>
using namespace std;

void FractalStar(int n, int x, int y)
{
	if(x / (n / 3) == 1 && y / (n / 3) == 1) printf(" ");
	else
	{
		if (n == 3) printf("*");
		else FractalStar(n / 3, x % (n / 3), y % (n / 3));
	}
}

int main()
{
	int n;
	cin >> n;
	
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
			FractalStar(n, x, y);
		printf("\n");
	}

	return 0;
}