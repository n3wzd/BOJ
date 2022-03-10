#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int target[100001];

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end());

	cin >> m;
	for (int i = 0; i < m; i++)
		scanf("%d", &target[i]);

	for (int i = 0; i < m; i++)
	{
		int start = 0, end = n - 1, mid = (start + end) / 2;
		bool ok = false;

		while (start <= end)
		{
			if (v[mid] == target[i])
			{
				ok = true;
				break;
			}
			else if (v[mid] < target[i]) start = mid + 1;
			else if (v[mid] > target[i]) end = mid - 1;
			mid = (start + end) / 2;
		}

		if (ok) printf("1\n");
		else printf("0\n");
	}

	return 0;
}