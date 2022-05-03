#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Edge {
public:
	int start, end, weight;
	Edge(int a, int b, int w) { start = a, end = b, weight = w; }
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.weight > b.weight;
	}
};

int N, M, island = 2, MST_cost = 0;
int parent[9];
int stage[11][11];
priority_queue<Edge, vector<Edge>, cmp> pq;
int dx[4] = { 1, 0, -1 ,0 };
int dy[4] = { 0, 1, 0 ,-1 };

int Find(int n)
{
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if (parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;
	parent[p1] += parent[p2];
	parent[p2] = p1;
}

bool Kruskal()
{
	for (int i = 0; i <= island; i++)
		parent[i] = -1;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (Find(next.start) == Find(next.end)) continue;

		MST_cost += next.weight;
		Union(next.start, next.end);
	}

	int root = Find(2);
	for (int i = 3; i < island; i++)
		if (root != Find(i))
			return 0;
	return 1;
}

void DFS(int x, int y, int id)
{
	stage[y][x] = id;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if(nx >= 0 && nx < M && ny >= 0 && ny < N)
			if (stage[ny][nx] == 1)
				DFS(nx, ny, id);
	}
}

void Bridge(int x, int y)
{
	int id = stage[y][x];
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i], ny = y + dy[i], dist = 0;
		bool sail = false;
		while (nx >= 0 && nx < M && ny >= 0 && ny < N)
		{
			if (stage[ny][nx] == id) break;
			else if (stage[ny][nx] != 0)
			{
				if(dist >= 2) sail = true;
				break;
			}
			nx += dx[i], ny += dy[i], dist++;
		}
		if (sail)
			pq.push(Edge(id, stage[ny][nx], dist));
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			scanf("%d", &stage[y][x]);

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (stage[y][x] == 1)
				DFS(x, y, island++);

	for (int y = 0; y < N; y++)
		for (int x = 0; x < M; x++)
			if (stage[y][x] >= 2)
				Bridge(x, y);

	if (Kruskal()) cout << MST_cost;
	else cout << -1;
	return 0;
}
