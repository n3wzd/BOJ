#include <iostream>
using namespace std;

int N, M;
int parent[500002];

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

	int cycle = 0;
	for (int i = 1; i <= M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (Find(a) == Find(b) && cycle == 0) cycle = i;
		Union(a, b);
	}
	cout << cycle;
	return 0;
}