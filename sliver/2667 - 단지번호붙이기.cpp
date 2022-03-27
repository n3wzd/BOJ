#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
# define MAX_SIZE 30

int N;
bool visited[MAX_SIZE][MAX_SIZE] = { 0, };
bool field[MAX_SIZE][MAX_SIZE] = { 0, };
int house = 0;
vector<int> village;

void DFS(int x, int y)
{
	if (x < 0 || x >= N || y < 0 || y >= N) return;
	if (visited[y][x] || !field[y][x]) return;
	visited[y][x] = true;
	house++;

	DFS(x+1, y);
	DFS(x-1, y);
	DFS(x, y+1);
	DFS(x, y-1);
}

int main()
{
	cin >> N;
	for (int y = 0; y < N; y++)
	{
		string s;
		cin >> s;
		for (int x = 0; x < N; x++)
			field[y][x] = s[x] - 48;
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (!visited[y][x] && field[y][x])
			{
				house = 0;
				DFS(x, y);
				village.push_back(house);
			}
		}
	}
	sort(village.begin(), village.end());

	int town = village.size();
	printf("%d\n", town);
	for (int i = 0; i < town; i++)
		printf("%d\n", village[i]);

	return 0;
}