#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> tree[1000002];
int adaptor = 0;

bool DFS(int v, int parent)
{
	bool c_adp = 1;
	int size = tree[v].size();
	for (int i = 0; i < size; i++)
	{
		int c = tree[v][i];
		if(c != parent) c_adp &= DFS(c, v);
	}
	if (!c_adp) adaptor++;
	return !c_adp;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 0);
	cout << adaptor;
	return 0;
}
