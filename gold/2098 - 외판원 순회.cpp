#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
int cache[16][1 << 16];
int graph[16][16];
const int INF = 20000000;

int DP(int v, int visited)
{
	if (cache[v][visited] > 0) return cache[v][visited];
	cache[v][visited] = INF;
	for (int w = 0; w < N; w++)
		if (!(visited & (1 << w)) && graph[v][w] != 0)
			cache[v][visited] = min(cache[v][visited], graph[v][w] + DP(w, visited | (1 << v)));
	if (graph[v][0] != 0 && (visited | (1 << v)) == (1 << N) - 1)
		cache[v][visited] = graph[v][0];
	return cache[v][visited];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> graph[y][x];

	cout << DP(0, 0);
	return 0;
}
