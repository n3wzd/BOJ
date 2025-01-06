#include <iostream>
using namespace std;

int main()
{
	long long N;
	long long sum = 0;
	cin >> N;
	for (long long n = 1; n <= N; n++)
		sum += N / n * n;
	cout << sum << endl;
	return 0;
}