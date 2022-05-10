#include <iostream>
#include <queue>
using namespace std;

int N, M;
int visited[102];
int warp[102];

void BFS(int s)
{
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		if (v == 100)
		{
			cout << visited[v] - 1;
			return;
		}

		for (int i = 1; i <= 6; i++)
		{
			int next = v + i;
			if (next > 100) next = 100;
			if (warp[next] > 0) next = warp[next];
			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[v] + 1;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		int a, b;
		cin >> a >> b;
		warp[a] = b;
	}

	BFS(1);
	return 0;
}