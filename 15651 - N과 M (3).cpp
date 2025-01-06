#include <iostream>
using namespace std;

int n, r;
int state[8];

void Permutation_Repetition(int index)
{
	if (index == r)
	{
		for (int i = 0; i < r; i++)
			printf("%d ", state[i] + 1);
		printf("\n");
		return;
	}

	for (int i = 0; i < n; i++)
	{
		state[index] = i;
		Permutation_Repetition(index + 1);
	}
}

int main()
{
	cin >> n >> r;
	Permutation_Repetition(0);
	return 0;
}