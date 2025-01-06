#include <iostream>
#include <cmath>
using namespace std;
const int MAXV = 999;

int main()
{
	int m = MAXV, sum = 0;
	for (int i = 0; i < 7; i++)
	{
		int num;
		scanf("%d", &num);
		if (num % 2 == 1)
		{
			m = min(m, num);
			sum += num;
		}
	}
		
	if (m == MAXV) cout << -1 << endl;
	else cout << sum << endl << m << endl;

	return 0;
}