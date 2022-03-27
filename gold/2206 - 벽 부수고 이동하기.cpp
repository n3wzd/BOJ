#include <iostream>
#include <queue>
using namespace std;
# define MAX_SIZE 1002

class Node {
public:
	int x, y, bomb;
	Node(int a, int b, int item) { x = a, y = b, bomb = item; }
};

int N, M;
int dist[MAX_SIZE][MAX_SIZE][2] = { 0, }; // value: 0 - no visit, 1,2,3... - distance from start
bool field[MAX_SIZE][MAX_SIZE] = { 0, };

int main()
{
	cin >> N >> M;
	for (int y = 0; y < N; y++)
	{
		string s;
		cin >> s;
		for (int x = 0; x < M; x++)
			field[y][x] = s[x] - 48;
	}

	queue<Node> q;
	Node snode(0, 0, 1);
	q.push(snode);
	dist[0][0][1] = 1;

	while (!q.empty())
	{
		Node v = q.front();
		int x = v.x, y = v.y, bomb = v.bomb;
		q.pop();

		if (x == M - 1 && y == N - 1) // destination
		{
			printf("%d\n", dist[y][x][bomb]);
			return 0;
		}

		for (int i = 0; i < 4; i++)
		{
			int nx, ny;
			switch (i)
			{
			case 0: nx = x + 1, ny = y; break;
			case 1: nx = x - 1, ny = y; break;
			case 2: nx = x, ny = y + 1; break;
			case 3: nx = x, ny = y - 1; break;
			}

			if (nx >= 0 && nx < M && ny >= 0 && ny < N)
			{
				if (dist[ny][nx][bomb] == 0)
				{
					if (field[ny][nx] == 0)
					{
						Node node(nx, ny, bomb);
						q.push(node);
						dist[ny][nx][bomb] = dist[y][x][bomb] + 1;
					}
					else if (bomb > 0)
					{
						Node node(nx, ny, bomb - 1);
						q.push(node);
						dist[ny][nx][bomb - 1] = dist[y][x][bomb] + 1;
					}
				}
			}
		}
	}

	cout << -1 << endl;
	return 0;
}