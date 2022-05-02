#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

class Edge {
public:
	int start, end;
	double weight;
	Edge(int a, int b, double w) { start = a, end = b, weight = w; }
};

struct cmp {
	bool operator()(Edge a, Edge b) {
		return a.weight > b.weight;
	}
};

int N, M;
double MST_cost = 0;
int parent[1002];
pair<int, int> space[1002];
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
	while (!pq.empty())
	{
		Edge next = pq.top();
		pq.pop();
		if (Find(next.start) == Find(next.end)) continue;

		MST_cost += next.weight;
		Union(next.start, next.end);
	}
}

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 0; i <= N; i++)
		parent[i] = -1;

	for (int i = 1; i <= N; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		space[i] = make_pair(a, b);
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		Union(a, b);
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = i + 1; j <= N; j++)
		{
			pair<int, int> pos1 = space[i], pos2 = space[j];
			pq.push(Edge(i, j, Distance(pos1.first, pos1.second, pos2.first, pos2.second)));
		}
	}

	Kruskal();
	printf("%.2f\n", round(MST_cost * 100) / 100);
	return 0;
}
