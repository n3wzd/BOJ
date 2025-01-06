#include <iostream>
using namespace std;

long long n;
long long digit[10];

int main()
{
	cin >> n;

	long long scale = 1;
	while (n >= scale)
	{
		long long pos = n % (scale * 10) / scale;
		long long right = n / (scale * 10);
		long long left = n % scale;

		for (int i = 0; i < 10; i++) digit[i] += right * scale;
		digit[0] -= scale;

		for (int i = 0; i < pos; i++) digit[i] += scale;
		digit[pos] += left + 1;

		scale *= 10;
	}

	for (int i = 0; i < 10; i++) cout << digit[i] << " ";
	cout << endl;
	return 0;
}