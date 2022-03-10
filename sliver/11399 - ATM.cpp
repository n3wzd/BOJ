#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> atm;
int sum = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int coin;
		cin >> coin;
		atm.push_back(coin);
	}
	sort(atm.begin(), atm.end());

	for (int i = 0; i < n; i++)
		sum += atm[i] * (n - i);

	cout << sum << endl;
	return 0;
}