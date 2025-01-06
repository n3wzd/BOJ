#include <iostream>
#include <map>
using namespace std;

int N, M;
int parent[200002];
map<string, int> friends;
int friends_size = 0;

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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i <= N * 2; i++)
			parent[i] = -1;

		for (int i = 0; i < N; i++)
		{
			string a, b;
			cin >> a >> b;
			if (friends.find(a) == friends.end()) friends.insert(make_pair(a, friends_size++));
			if (friends.find(b) == friends.end()) friends.insert(make_pair(b, friends_size++));

			int f1 = friends.find(a)->second;
			int f2 = friends.find(b)->second;
			Union(f1, f2);
			cout << -parent[Find(f1)] << "\n";
		}

		friends_size = 0;
		friends.clear();
	}
	return 0;
}