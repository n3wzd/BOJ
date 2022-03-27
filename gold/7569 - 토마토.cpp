#include <iostream>
#include <utility>
#include <queue>
using namespace std;
# define MAX_SIZE 102

class Node {
public:
	int x, y, z;
	Node(int a, int b, int c) { x = a, y = b, z = c; }
};

int N, M, H;
int min_dist[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0, }; // value: 0 - no visit, 1,2,3... - distance from start
int field[MAX_SIZE][MAX_SIZE][MAX_SIZE] = { 0, };

int main()
{
	queue<Node> q;
	cin >> M >> N >> H;
	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				scanf("%d", &field[z][y][x]);
				if (field[z][y][x] == 1)
				{
					Node node(x, y, z);
					q.push(node);
				}
			}
		}
	}
	

	while (!q.empty())
	{
		Node v = q.front();
		int x = v.x, y = v.y, z = v.z;
		q.pop();

		for (int i = 0; i < 6; i++)
		{
			int nx, ny, nz;
			switch (i)
			{
			case 0: nx = x + 1, ny = y, nz = z; break;
			case 1: nx = x - 1, ny = y, nz = z; break;
			case 2: nx = x, ny = y + 1, nz = z; break;
			case 3: nx = x, ny = y - 1, nz = z; break;
			case 4: nx = x, ny = y, nz = z + 1; break;
			case 5: nx = x, ny = y, nz = z - 1; break;
			}

			if (nx >= 0 && nx < M && ny >= 0 && ny < N && nz >= 0 && nz < H)
			{
				if ((min_dist[nz][ny][nx] == 0 || min_dist[nz][ny][nx] > min_dist[z][y][x] + 1) && field[nz][ny][nx] == 0)
				{
					Node node(nx, ny, nz);
					q.push(node);
					min_dist[nz][ny][nx] = min_dist[z][y][x] + 1;
				}
			}
		}
	}

	int min_day = 0;
	for (int z = 0; z < H; z++)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (field[z][y][x] == 0 && min_dist[z][y][x] == 0)
				{
					cout << -1 << endl;
					return 0;
				}

				if (min_dist[z][y][x] > min_day)
					min_day = min_dist[z][y][x];
			}
		}
	}
	cout << min_day << endl;
	return 0;
}