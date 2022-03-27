#include <iostream>
#include <vector>
using namespace std;
# define MAX_SIZE 52

int N, M, K;
bool visited[MAX_SIZE][MAX_SIZE] = { 0, };
bool field[MAX_SIZE][MAX_SIZE] = { 0, };
int caterpillar = 0;

void DFS(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (visited[y][x] || !field[y][x]) return;
	visited[y][x] = true;

	DFS(x+1, y);
	DFS(x-1, y);
	DFS(x, y+1);
	DFS(x, y-1);
}

int main()
{
	int t;
	scanf("%d", &t);

	while (t--)
	{
		// 초기화
		for (int y = 0; y < MAX_SIZE; y++)
		{
			for (int x = 0; x < MAX_SIZE; x++)
			{
				visited[y][x] = 0;
				field[y][x] = 0;
			}
		}
		caterpillar = 0;

		// 시작
		scanf("%d%d%d", &M, &N, &K);
		for (int i = 0; i < K; i++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			field[y][x] = 1;
		}

		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				if (!visited[y][x] && field[y][x])
				{
					DFS(x, y);
					caterpillar++;
				}
			}
		}

		printf("%d\n", caterpillar);
	}
	return 0;
}