#include <iostream>
using namespace std;

int arr[8];
int n;

int state[8]; // current state in recursive function -> index sequence of arr
bool visited[8] = { 0, };

void Print()
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[state[i]]);
	printf("\n");
}

void DFS(int index)
{
	if (index == n)
	{
		Print();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			visited[i] = true;
			state[index] = i;
			DFS(index + 1);
			// visited[i] = false;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	DFS(0);
	return 0;
}