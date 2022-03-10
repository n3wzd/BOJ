#include <iostream>
using namespace std;

int arr[8]; // assume that arr is sorted array.
int n, r;

int state[8]; // current state in recursive function -> index sequence of arr
bool visited[8] = { 0, }; // used in Permutation()
int preValue = -1;
int start = 0;

void Print()
{
	for (int i = 0; i < r; i++)
		printf("%d ", arr[state[i]]);
	printf("\n");
}

void Combination(int index)
{
	if (index == r)
	{
		Print();
		return;
	}

	for (int i = start; i < n; i++)
	{
		state[index] = i;
		start = i + 1;
		Combination(index + 1);
	}
}

void Combination_Repetition(int index)
{
	if (index == r)
	{
		Print();
		return;
	}

	for (int i = start; i < n; i++)
	{
		state[index] = i;
		start = i;
		Combination_Repetition(index + 1);
	}
}

void Permutation(int index)
{
	if (index == r)
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
			Permutation(index + 1);
			visited[i] = false;
		}
	}
}

void Permutation2(int index)
{
	if (index == r)
	{
		Print();
		return;
	}
	int preValue = -1;

	for (int i = 0; i < n; i++)
	{
		bool ok = true;
		if (visited[i]) ok = false;
		else
		{
			if (arr[i] == preValue && preValue != -1) ok = false; // containing the same
			preValue = arr[i];
		}

		if (ok)
		{
			visited[i] = true;
			state[index] = i;
			Permutation(index + 1);
			visited[i] = false;
		}
	}
}

void Permutation_Repetition(int index)
{
	if (index == r)
	{
		Print();
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
	cout << "n, r: ";
	cin >> n >> r;
	cout << "arr: ";
	for (int i = 0; i < n; i++) cin >> arr[i];

	cout << "nPr" << endl;
	Permutation(0);
	cout << endl;

	cout << "n¢³r" << endl;
	Permutation_Repetition(0);
	cout << endl;

	start = 0;
	cout << "nCr" << endl;
	Combination(0);
	cout << endl;

	start = 0;
	cout << "nHr" << endl;
	Combination_Repetition(0);
	cout << endl;

	return 0;
}