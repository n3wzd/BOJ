#include <iostream>
using namespace std;

int N, M;
int parent[1000002];

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

	for (int i = 0; i < M; i++)
	{
		int cmd, a, b;
		scanf("%d%d%d", &cmd, &a, &b);
		if (cmd == 0) Union(a, b);
		else
		{
			if (Find(a) == Find(b)) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}