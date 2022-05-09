#include <iostream>
using namespace std;

int N, sum = 0;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 9; i++)
	{
		int num;
		cin >> num;
		sum += num;
	}
	cout << N - sum;
	return 0;
}
