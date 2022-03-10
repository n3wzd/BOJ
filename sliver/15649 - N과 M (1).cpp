#include <iostream>
#include <vector>
using namespace std;

void Com(vector<int> v, vector<int> w, int limit, int target)
{
	if (target != -1)
	{
		w.push_back(v[target]);
		v.erase(v.begin() + target);
	}

	if (limit > 0)
	{
		int len = v.size();
		for (int i = 0; i < len; i++)
			Com(v, w, limit-1, i);
	}
	else
	{
		int len = w.size();
		for (int i = 0; i < len; i++)
			printf("%d ", w[i]);
		printf("\n");
	}
}

int main()
{
	int n, m;
	vector<int> v, w;
	cin >> n >> m;
	for (int i = 0; i < n; i++) v.push_back(i+1);

	Com(v, w, m, -1);
	return 0;
}