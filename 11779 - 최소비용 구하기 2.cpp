#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define INF 1999999999

class Node {
public:
	int v, d, prev;
	Node(int a, int b, int c) { v = a, d = b, prev = c; }
};

struct cmp {
	bool operator()(Node& a, Node& b) {
		return (a.d == b.d) ? a.v > b.v : a.d > b.d;
	}
};

int N, M, S, T;
int track[1002];
int dist[1002];
bool visited[1002] = { 0, };
vector<pair<int, int>> graph[1002];
priority_queue<Node, vector<Node>, cmp> pq;

void Dijkstra(int S)
{
	for (int i = 1; i <= N; i++)
	{
		dist[i] = INF;
		visited[i] = 0;
	}
	dist[S] = 0;

	pq.push(Node(S, 0, 0));
	while (!pq.empty())
	{
		Node node = pq.top();
		int v = node.v;
		pq.pop();
		if (visited[v]) continue;
		track[v] = node.prev;
		visited[v] = 1;

		int len = graph[v].size();
		for (int i = 0; i < len; i++)
		{
			int nv = graph[v][i].first;
			int w = graph[v][i].second;
			if (dist[v] + w < dist[nv])
			{
				dist[nv] = dist[v] + w;
				pq.push(Node(nv, dist[nv], v));
			}
		}
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		graph[a].push_back(make_pair(b, w));
	}
	scanf("%d%d", &S, &T);

	Dijkstra(S);
	printf("%d\n", dist[T]);

	stack<int> stk;
	int idx = T;
	while (idx != 0)
	{
		stk.push(idx);
		idx = track[idx];
	}

	printf("%d\n", stk.size());
	while (!stk.empty())
	{
		printf("%d ", stk.top());
		stk.pop();
	}
		
	return 0;
}