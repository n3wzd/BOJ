#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int pos_count[4001] = { 0, };
int neg_count[4001] = { 0, };

int main()
{
	vector<int> arr, freq_ind;
	int n, freq_max = -1;
	double sum = 0, avg;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int c;
		scanf("%d", &c);
		arr.push_back(c);

		sum += c;
		if (c >= 0) pos_count[c]++;
		else neg_count[abs(c)]++;
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i <= 4000; i++)
	{
		if (freq_max < pos_count[i])
			freq_max = pos_count[i];
	}
	for (int i = 1; i <= 4000; i++)
	{
		if (freq_max < neg_count[i])
			freq_max = neg_count[i];
	}
	for (int i = 0; i <= 4000; i++)
	{
		if (freq_max == pos_count[i])
			freq_ind.push_back(i);
	}
	for (int i = 1; i <= 4000; i++)
	{
		if (freq_max == neg_count[i])
			freq_ind.push_back(-i);
	}
	sort(freq_ind.begin(), freq_ind.end());

	avg = round(sum / n);
	if (avg == 0) avg = 0; // detect negative zero 

	cout << avg << endl;
	cout << arr[n / 2] << endl;
	if (freq_ind.size() > 1) cout << freq_ind[1] << endl;
	else cout << freq_ind[0] << endl;
	cout << abs(arr[n - 1] - arr[0]) << endl;

	return 0;
}