#include <iostream>
#include <stack>
#include <queue>
#include <memory.h>
using namespace std;
# define LEN 10002

typedef struct Trace {
	int prev;
	int code;
} Trace;

int N, K;
int dist[LEN];
bool visited[LEN];
Trace trace[LEN];

void Print(int x)
{
	stack<int> stk;
	int mv = x;
	while (trace[mv].prev != -1)
	{
		stk.push(mv);
		mv = trace[mv].prev;
	}
	while (!stk.empty())
	{
		int code = trace[stk.top()].code;
		if (code == 0) printf("D");
		if (code == 1) printf("S");
		if (code == 2) printf("L");
		if (code == 3) printf("R");
		stk.pop();
	}
	printf("\n");
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	dist[start] = 0;
	visited[start] = 1;
	trace[start].prev = -1;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();

		if (x == K)
		{
			Print(x);
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx;
			if (i == 0) nx = (x * 2) % 10000;
			if (i == 1) nx = (x > 0) ? x - 1 : 9999;
			if (i == 2) nx = x * 10 + (x / 1000) - ((x / 1000) * 10000);
			if (i == 3) nx = x / 10 + ((x % 10) * 1000);

			if (nx >= 0 && nx < LEN)
			{
				if (!visited[nx])
				{
					q.push(nx);
					dist[nx] = dist[x] + 1;
					visited[nx] = 1;
					trace[nx].prev = x;
					trace[nx].code = i;
				}
			}
		}
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(visited, 0, LEN);
		scanf("%d%d", &N, &K);
		BFS(N);
	}
	return 0;
}