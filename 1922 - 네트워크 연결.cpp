#include <iostream>
#include <queue>
#include <vector>
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

int N, M, MST_cost = 0;
int parent[1002];
priority_queue<Edge, vector<Edge>, cmp> pq;

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

void Kruskal()
{
	for (int i = 0; i <= N; i++)
		parent[i] = -1;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (Find(next.start) == Find(next.end)) continue;

		MST_cost += next.weight;
		Union(next.start, next.end);
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		pq.push(Edge(a, b, w));
	}
	Kruskal();
	cout << MST_cost;
	return 0;
}
