#include <iostream>
#include <queue>
using namespace std;
# define MAXV 202

class Node {
public:
	int x, y, jump;
	Node(int a, int b, int c) { x = a, y = b, jump = c; }
};

int K, W, H;
bool board[MAXV][MAXV] = { 0, };
int dist[32][MAXV][MAXV] = { 0, };
int horse_dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
int horse_dy[8] = { 1, 2, 2 ,1, -1, -2, -2, -1 };
int monkey_dx[4] = { 1, 0, -1 ,0 };
int monkey_dy[4] = { 0, 1, 0, -1 };

int main()
{
	int K, W, H;
	scanf("%d%d%d", &K, &W, &H);
	for (int y = 0; y < H; y++)
		for (int x = 0; x < W; x++)
			scanf("%d", &board[y][x]);

	queue<Node> q;
	q.push(Node(0, 0, K));

	while (!q.empty())
	{
		Node v = q.front();
		q.pop();
		int x = v.x, y = v.y, jump = v.jump;

		if (x == W-1 && y == H-1) // destination
		{
			printf("%d\n", dist[jump][y][x]);
			return 0;
		}

		if (jump > 0)
		{
			for (int i = 0; i < 8; i++)
			{
				int nx = x + horse_dx[i], ny = y + horse_dy[i];
				if (nx >= 0 && nx < W && ny >= 0 && ny < H)
				{
					if (dist[jump - 1][ny][nx] == 0 && board[ny][nx] == 0)
					{
						q.push(Node(nx, ny, jump - 1));
						dist[jump - 1][ny][nx] = dist[jump][y][x] + 1;
					}
				}
			}
		}
		
		for (int i = 0; i < 4; i++)
		{
			int nx = x + monkey_dx[i], ny = y + monkey_dy[i];
			if (nx >= 0 && nx < W && ny >= 0 && ny < H)
			{
				if (dist[jump][ny][nx] == 0 && board[ny][nx] == 0)
				{
					q.push(Node(nx, ny, jump));
					dist[jump][ny][nx] = dist[jump][y][x] + 1;
				}
			}
		}
	}
	printf("-1\n");
	return 0;
}