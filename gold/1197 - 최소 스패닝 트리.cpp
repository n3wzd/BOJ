#include <iostream>
#include <vector>
#include <queue>
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

int V, E, MST_cost = 0;
vector<Edge> graph[10002];
priority_queue<Edge, vector<Edge>, cmp> pq;
bool visited[10002];

void AddEdge(int v)
{
	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		Edge next = graph[v][i];
		if (!visited[next.end]) pq.push(next);
	}
}

void Prim()
{
	AddEdge(1);
	visited[1] = true;

	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (visited[next.end]) continue;

		MST_cost += next.weight;
		AddEdge(next.end);
		visited[next.end] = true;
	}
}

int parent[20002];
priority_queue<Edge, vector<Edge>, cmp> pq2;

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
	for (int i = 0; i <= V; i++)
		parent[i] = -1;

	while (!pq2.empty())
	{
		Edge next = pq2.top();
		pq2.pop();
		if (Find(next.start) == Find(next.end)) continue;

		MST_cost += next.weight;
		Union(next.start, next.end);
	}
}

int main()
{
	scanf("%d%d", &V, &E);
	for (int i = 0; i < E; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(Edge(a, b, w));
		graph[b].push_back(Edge(b, a, w));
		pq2.push(Edge(a, b, w));
	}
	
	// Prim();
	Kruskal();
	cout << MST_cost;
	return 0;
}