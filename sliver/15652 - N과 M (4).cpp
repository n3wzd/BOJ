#include <iostream>
using namespace std;

int n, r;
int state[8];
int start = 0;

void Combination_Repetition(int index)
{
	if (index == r)
	{
		for (int i = 0; i < r; i++)
			printf("%d ", state[i] + 1);
		printf("\n");
		return;
	}

	for (int i = start; i < n; i++)
	{
		state[index] = i;
		start = i;
		Combination_Repetition(index + 1);
	}
}

int main()
{
	cin >> n >> r;
	Combination_Repetition(0);
	return 0;
}