#include <iostream>
#include <utility>
#include <queue>
#include <cmath>
using namespace std;

int V;
double MST_cost = 0;
pair<double, double> starmap[102];
priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
bool visited[102];

double Distance(double x1, double y1, double x2, double y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void AddEdge(int v)
{
	double x = starmap[v].first, y = starmap[v].second;
	for (int i = 0; i < V; i++)
		if (!visited[i])
			pq.push(pair<double, int>(Distance(x, y, starmap[i].first, starmap[i].second), i));
}

void Prim()
{
	AddEdge(0);
	visited[0] = true;

	while (!pq.empty())
	{
		pair<double, int> next = pq.top();
		pq.pop();
		if (visited[next.second]) continue;

		MST_cost += next.first;
		AddEdge(next.second);
		visited[next.second] = true;
	}
}

int main()
{;
	scanf("%d", &V);
	for (int i = 0; i < V; i++)
	{
		double a, b;
		scanf("%lf%lf", &a, &b);
		starmap[i] = make_pair(a, b);
	}
	
	Prim();
	printf("%.2f\n", MST_cost);
	return 0;
}
