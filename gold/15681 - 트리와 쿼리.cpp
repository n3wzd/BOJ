#include <iostream>
#include <vector>
using namespace std;

int N, R, Q;
vector<int> tree[100002];
int cnt[100002];

int DFS(int v)
{
	cnt[v] = 1;
	int size = tree[v].size();
	for (int i = 0; i < size; i++)
	{
		int w = tree[v][i];
		if(cnt[w] == 0)
			cnt[v] += DFS(w);
	}
	return cnt[v];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> R >> Q;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(R);
	for (int i = 0; i < Q; i++)
	{
		int q;
		cin >> q;
		cout << cnt[q] << "\n";
	}

	return 0;
}
