#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a * a;
	}
	cout << sum % 10 << endl;
	return 0;
}