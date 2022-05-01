#include <iostream>
using namespace std;

int N, M;
int parent[202];

int Find(int n)
{
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if(parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2])
	{
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else
	{
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i <= N; i++)
		parent[i] = -1;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			int ok;
			scanf("%d", &ok);
			if (ok == 1) Union(i, j);
		}
	}

	int root, first;
	bool travel = 1;
	scanf("%d", &first);
	root = Find(first);
	for (int i = 1; i < M; i++)
	{
		int city;
		scanf("%d", &city);
		if (root != Find(city))
			travel = 0;
	}

	if (travel) cout << "YES";
	else cout << "NO";
	return 0;
}