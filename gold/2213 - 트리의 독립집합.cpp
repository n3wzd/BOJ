#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> tree[10002];
int weight[10002];
int cache[10002][2];
vector<pair<int, int>> trace[10002][2];
vector<int> idpset;

int DFS(int v, int idp, int parent)
{
	if (cache[v][idp] > 0) return cache[v][idp];

	int size = tree[v].size();
	for (int i = 0; i < size; i++)
	{
		int c = tree[v][i];
		if (c == parent) continue;

		DFS(c, 0, v), DFS(c, 1, v);
		int pick;
		if (idp == 1) pick = 0;
		else if (cache[c][0] > cache[c][1]) pick = 0;
		else pick = 1;

		cache[v][idp] += cache[c][pick];
		trace[v][idp].push_back(make_pair(c, pick));
	}
	if (idp == 1) cache[v][idp] += weight[v];
	return cache[v][idp];
}

void TraceDFS(int v, int idp)
{
	if (idp == 1) idpset.push_back(v);
	int size = trace[v][idp].size();
	for (int i = 0; i < size; i++)
		TraceDFS(trace[v][idp][i].first, trace[v][idp][i].second);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> weight[i];
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	DFS(1, 0, 0), DFS(1, 1, 0);
	int pick = (cache[1][0] > cache[1][1]) ? 0 : 1;
	cout << cache[1][pick] << "\n";
	TraceDFS(1, pick);
	sort(idpset.begin(), idpset.end());

	int size = idpset.size();
	for (int i = 0; i < size; i++)
		cout << idpset[i] << " ";

	return 0;
}
