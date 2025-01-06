#include <iostream>
#include <cmath>
using namespace std;
bool result[100000] = {0, };

int main()
{
	int len = 0;

	while (1)
	{
		double a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0) break;

		if (pow(a, 2) + pow(b, 2) == c * c) result[len] = 1;
		else if (pow(b, 2) + pow(c, 2) == a * a) result[len] = 1;
		else if (pow(c, 2) + pow(a, 2) == b * b) result[len] = 1;
		len++;
	}
	
	for (int i = 0; i < len; i++)
	{
		if (result[i]) printf("right\n");
		else printf("wrong\n");
	}

	return 0;
}