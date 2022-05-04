#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[10002];
int villager[10002];
int cache[10002][2];

int DFS(int v, int excel, int parent)
{
	if (cache[v][excel] > 0) return cache[v][excel];

	int size = tree[v].size();
	for (int i = 0; i < size; i++)
	{
		int c = tree[v][i];
		if (c != parent)
		{
			if(excel == 1) cache[v][excel] += DFS(c, 0, v);
			else cache[v][excel] += max(DFS(c, 0, v), DFS(c, 1, v));
		}
	}
	if (excel == 1) cache[v][excel] += villager[v];
	return cache[v][excel];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> villager[i];
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	cout << max(DFS(1, 0, 0), DFS(1, 1, 0));
	return 0;
}
