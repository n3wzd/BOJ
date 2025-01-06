#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;

class Point {
public:
	int x, y, z, id;
	Point() { }
	Point(int a, int b, int c, int i ) { x = a, y = b, z = c, id = i; }
};

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

int sort_mode;
bool sort_cmp(Point a, Point b) {
	return (sort_mode == 0) ? a.x < b.x : ((sort_mode == 1) ? a.y < b.y : a.z < b.z);
}

int N, MST_cost = 0;
int parent[100002];
Point planet[100002];
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

int Distance(Point p1, Point p2)
{
	return min(abs(p2.x - p1.x), min(abs(p2.y - p1.y), abs(p2.z - p1.z)));
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		planet[i] = Point(a, b, c, i);
	}
	for (sort_mode = 0; sort_mode < 3; sort_mode++)
	{
		sort(planet + 1, planet + N + 1, sort_cmp);
		for (int i = 2; i <= N; i++)
			pq.push(Edge(planet[i - 1].id, planet[i].id, Distance(planet[i - 1], planet[i])));
	}

	Kruskal();
	printf("%d\n", MST_cost);
	return 0;
}
