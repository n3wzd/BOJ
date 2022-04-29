#include <iostream>
#include <vector>
using namespace std;

int N;
int graph[30][2];
int mode;

void DFS(int v)
{
	if (mode == 0) printf("%c", v + 64);
	if (graph[v][0] != 0) DFS(graph[v][0]);
	if (mode == 1) printf("%c", v + 64);
	if (graph[v][1] != 0) DFS(graph[v][1]);
	if (mode == 2) printf("%c", v + 64);
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		char a, b, c;
		cin >> a >> b >> c;
		if (b != '.') graph[a - 64][0] = (int(b - 64));
		if (c != '.') graph[a - 64][1] = (int(c - 64));
	}
	for (int i = 0; i < 3; i++)
	{
		mode = i;
		DFS(1);
		printf("\n");
	}
	return 0;
}