#include <iostream>
#include <stack>
#include <queue>
using namespace std;
# define MAXV 100002

int N, K;
int dist[MAXV];
bool visited[MAXV];
int trace[MAXV];

void Print(int x)
{
	printf("%d\n", dist[x]);
	stack<int> stk;
	int mv = x;
	while (mv != -1)
	{
		stk.push(mv);
		mv = trace[mv];
	}
	while (!stk.empty())
	{
		printf("%d ", stk.top());
		stk.pop();
	}
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = 1;
	trace[start] = -1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == K)
		{
			Print(x);
			return;
		}

		for (int i = 0; i < 3; i++)
		{
			int nx;
			if (i == 0) nx = x + 1;
			if (i == 1) nx = x - 1;
			if (i == 2) nx = x * 2;

			if (nx >= 0 && nx < MAXV)
			{
				if (!visited[nx])
				{
					q.push(nx);
					dist[nx] = dist[x] + 1;
					visited[nx] = 1;
					trace[nx] = x;
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;
	BFS(N);
	return 0;
}