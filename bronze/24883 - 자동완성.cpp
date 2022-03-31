#include <iostream>
using namespace std;

int main()
{
	char n;
	cin >> n;

	if (n == 'n' || n == 'N') printf("Naver D2\n");
	else printf("Naver Whale\n");
	return 0;
}

/*
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
#define INF 99999999

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

int N, M, T, S, G, H;;
int dest[102];
int track[2002];

int dist[2002];
bool visited[2002] = { 0, };
vector<pair<int, int>> graph[2002];
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
	int t;
	scanf("%d", &t);

	while (t--)
	{
		scanf("%d%d%d%d%d%d", &N, &M, &T, &S, &G, &H);
		for (int i = 1; i <= M; i++)
		{
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			graph[a].push_back(make_pair(b, w));
			graph[b].push_back(make_pair(a, w));
		}
		for (int i = 1; i <= T; i++)
			scanf("%d", &dest[i]);

		Dijkstra(S);
		for (int i = 1; i <= N; i++)
			cout << track[i] << " ";
	}
	return 0;
}
*/