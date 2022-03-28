#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int state[20002] = { 0, }; // 0 - non-visited, 1 - set A, -1 - set B
vector<int> graph[20002];

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		// input
		int V, E;
		scanf("%d%d", &V, &E);
		for (int i = 1; i <= V; i++)
		{
			state[i] = 0;
			graph[i].clear();
		}
		for (int i = 0; i < E; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			graph[a].push_back(b);
			graph[b].push_back(a);
		}

		// start
		bool isBip = true;
		for (int S = 1; S <= V; S++)
		{
			if (state[S] != 0) continue;

			queue<int> q;
			q.push(S);
			state[S] = 1;

			while (!q.empty())
			{
				int v = q.front();
				q.pop();

				int len = graph[v].size();
				for (int i = 0; i < len; i++)
				{
					int nv = graph[v][i];

					if (state[nv] == 0)
					{
						q.push(nv);
						state[nv] = -state[v];
					}
					else if (state[nv] == state[v])
						isBip = false;
				}
				if (!isBip) break;
			}
			if (!isBip) break;
		}

		if (isBip) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}