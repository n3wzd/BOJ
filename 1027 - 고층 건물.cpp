#include <iostream>
#include <cmath>
using namespace std;

int N, view = 0;
int city[53];

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		scanf("%d", &city[i]);

	for (int i = 1; i <= N; i++)
	{
		int left = i - 1, right = i + 1;
		int look = 0;
		double max_tan = 0;

		while(left > 0)
		{
			double tan = (double)(city[left] - city[i]) / abs(i - left);
			if (tan > max_tan || left == i - 1) look++;
			max_tan = (left == i - 1) ? tan : max(tan, max_tan); left--;
		}
		
		while (right <= N)
		{
			double tan = (double)(city[right] - city[i]) / abs(right - i);
			if (tan > max_tan || right == i + 1) look++;
			max_tan = (right == i + 1) ? tan : max(tan, max_tan); right++;
		}

		view = max(view, look);
	}

	cout << view << endl;
	return 0;
}