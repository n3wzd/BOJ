#include <iostream>
using namespace std;

int main()
{
	int n, index = 1, result = 0;
	cin >> n;

	while (index < n)
	{
		int sum = index;
		for (int i = index; i > 0; i /= 10)
			sum += i % 10;

		if (sum == n)
		{
			result = index;
			break;
		}
		index++;
	}

	cout << result << endl;
	return 0;
}