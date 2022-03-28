#include <iostream>
#include <queue>
using namespace std;
# define MAXV 302

class Node {
public:
	int x, y;
	Node(int a, int b) { x = a, y = b; }
};

int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2 ,1, -1, -2, -2, -1 };

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N, goal_x, goal_y, sx, sy;
		int dist[MAXV][MAXV] = { 0, };
		scanf("%d %d%d %d%d", &N, &sx, &sy, &goal_x, &goal_y);

		queue<Node> q;
		q.push(Node(sx, sy));

		while (!q.empty())
		{
			Node v = q.front();
			q.pop();
			int x = v.x, y = v.y;

			if (x == goal_x && y == goal_y) // destination
			{
				printf("%d\n", dist[y][x]);
				break;
			}

			for (int i = 0; i < 8; i++)
			{
				int nx = x + dx[i], ny = y + dy[i];

				if (nx >= 0 && nx < N && ny >= 0 && ny < N)
				{
					if (dist[ny][nx] == 0)
					{
						q.push(Node(nx, ny));
						dist[ny][nx] = dist[y][x] + 1;
					}
				}
			}
		}
	}
	return 0;
}