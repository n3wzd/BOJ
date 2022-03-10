#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int target;

bool BinarySearch()
{
	int start = 0;
	int end = v.size() - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;
		if (v[mid] == target) return true;
		else if (v[mid] < target) start = mid + 1;
		else if (v[mid] > target) end = mid - 1;
	}

	return false;
}

int LowerBound()
{
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (v[mid] < target) start = mid + 1;
		else end = mid;
	}

	return end;
}

int UpperBound()
{
	int start = 0;
	int end = v.size() - 1;
	int mid = 0;

	while (start < end)
	{
		mid = (start + end) / 2;
		if (v[mid] <= target) start = mid + 1;
		else end = mid;
	}

	return end;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> target;
	cout << BinarySearch() << endl;
	cout << LowerBound() << endl;
	cout << UpperBound() << endl;
	return 0;
}