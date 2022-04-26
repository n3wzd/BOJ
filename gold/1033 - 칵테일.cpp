#include <iostream>
#include <vector>
using namespace std;

int N;
long long recipe[11];
vector<int> conn[11];
bool visited[11];

long long GCD(long long a, long long b)
{
	return (a % b == 0) ? b : GCD(b, a % b);
}

void DFS(long long v, long long d)
{
	visited[v] = true;
	recipe[v] *= d;

	int len = conn[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = conn[v][i];
		if (!visited[next])
		{
			DFS(next, d);
			visited[next] = true;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) recipe[i] = 1;

	for (int i = 0; i < N - 1; i++)
	{
		long long v, w, a, b;
		cin >> v >> w >> a >> b;

		long long g = GCD(a, b);
		a /= g, b /= g;

		long long g1 = (a * recipe[v]) / GCD(a, recipe[v]);
		long long g2 = (b * recipe[w]) / GCD(b, recipe[w]);
		long long g3 = ((g1 / a) * (g2 / b)) / GCD((g1 / a), (g2 / b));

		for (int i = 0; i < N; i++) visited[i] = 0;
		DFS(v, (g3 * a) / recipe[v]);
		for (int i = 0; i < N; i++) visited[i] = 0;
		DFS(w, (g3 * b) / recipe[w]);

		conn[v].push_back(w);
		conn[w].push_back(v);
	}
	
	for (int i = 0; i < N; i++)
		cout << recipe[i] << " ";

	return 0;
}