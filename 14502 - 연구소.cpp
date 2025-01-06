#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, M, safe = 0;
bool visited[9][9] = { 0, };
int map[9][9] = { 0, };
int map_test[9][9];

int state[4];
vector<pair<int, int>> empty_pos;
int empty_len;

void DFS(int x, int y)
{
	if (x < 0 || x >= M || y < 0 || y >= N) return;
	if (visited[y][x] || map_test[y][x] == 1) return;
	visited[y][x] = 1;
	map_test[y][x] = 2;

	DFS(x + 1, y);
	DFS(x - 1, y);
	DFS(x, y + 1);
	DFS(x, y - 1);
}

void Combination(int index, int start)
{
	if (index == 3)
	{
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				map_test[y][x] = map[y][x];
				visited[y][x] = 0;
			}
		}		

		// install 3 wall
		for (int i = 0; i < 3; i++)
		{
			pair<int, int> wall = empty_pos[state[i]];
			int wx = wall.first, wy = wall.second;
			map_test[wy][wx] = 1;
		}
		
		// !! virus warning !!
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (!visited[y][x] && map_test[y][x] == 2)
					DFS(x, y);

		// find safezone
		int safe_test = 0;
		for (int y = 0; y < N; y++)
			for (int x = 0; x < M; x++)
				if (map_test[y][x] == 0)
					safe_test++;

		if (safe_test > safe) safe = safe_test;
		return;
	}

	for (int i = start; i < empty_len; i++)
	{
		state[index] = i;
		Combination(index + 1, i + 1);
	}
}

int main()
{
	scanf("%d%d", &N, &M);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			scanf("%d", &map[y][x]);
			if (map[y][x] == 0)
				empty_pos.push_back(make_pair(x, y));
		}
	}
	empty_len = empty_pos.size();

	Combination(0, 0);
	printf("%d\n", safe);
	return 0;
}