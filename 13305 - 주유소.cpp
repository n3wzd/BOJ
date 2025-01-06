#include <iostream>
using namespace std;

long long road[100002];
long long oilbank[100002];
long long n, cost = 0, min_oil = 0, dist = 0;

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; i++)
		scanf("%lld", &road[i]);
	for (int i = 0; i < n; i++)
		scanf("%lld", &oilbank[i]);

	min_oil = oilbank[0];
	dist += road[0];
	for (int i = 1; i < n - 1; i++)
	{
		if (oilbank[i] < min_oil)
		{
			cost += dist * min_oil;
			min_oil = oilbank[i];
			dist = 0;
		}
		dist += road[i];
	}
	cost += dist * min_oil;

	cout << cost << endl;
	return 0;
}