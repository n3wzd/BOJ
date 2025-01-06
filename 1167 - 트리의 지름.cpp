#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Edge {
public:
	int end;
	int cost;
	Edge(int p1, int p2) { end = p1, cost = p2; };
};

int N;
bool visited[100002];
vector<Edge> graph[100002];
int diameter = 0;

int DFS(int v)
{
	visited[v] = true;

	priority_queue<int> pq;
	int len = graph[v].size();
	for (int i = 0; i < len; i++)
	{
		int next = graph[v][i].end;
		if (!visited[next])
			pq.push(DFS(next) + graph[v][i].cost);
	}

	int pq_size = pq.size();
	int max1 = 0, max2;
	if (pq_size == 0) max1 = 0;
	else if (pq_size == 1)
	{
		max1 = pq.top();
		diameter = max(diameter, max1);
	}
	else
	{
		max1 = pq.top(), pq.pop();
		max2 = pq.top();
		diameter = max(diameter, max1 + max2);
	}
	return max1;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int v, end, cost;
		scanf("%d", &v);
		while (1)
		{
			scanf("%d", &end);
			if (end == -1) break;
			scanf("%d", &cost);
			graph[v].push_back(Edge(end, cost));
		}
	}

	DFS(1);
	cout << diameter << endl;
	return 0;
}