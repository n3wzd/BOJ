#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n;
int status[20][20] = { 0, };
int result = -1;

int team_link[10];
int team_start[10];
int start = 0;

void Matching()
{
	int sum_link = 0, sum_start = 0, diff;
	bool team_match[20] = { 0, }; // 0 - start, 1 - link
	int mb1, mb2, idx = 0;

	// get status of Team Link
	for (int i = 0; i < n / 2; i++)
	{
		mb1 = team_link[i];
		for (int j = 0; j < n / 2; j++)
		{
			mb2 = team_link[j];
			sum_link += status[mb1][mb2];
		}
		team_match[mb1] = true;
	}

	// matching Team Start
	for (int i = 0; i < n; i++)
	{
		if (!team_match[i])
		{
			team_start[idx] = i;
			idx++;
		}
	}

	// get status of Team Start
	for (int i = 0; i < n / 2; i++)
	{
		mb1 = team_start[i];
		for (int j = 0; j < n / 2; j++)
		{
			mb2 = team_start[j];
			sum_start += status[mb1][mb2];
		}
	}

	diff = abs(sum_link - sum_start);
	if (result > diff || result == -1) result = diff;
}

void Combination(int index)
{
	if (index == n / 2)
	{
		Matching();
		return;
	}

	for (int i = start; i < n; i++)
	{
		team_link[index] = i;
		start = i + 1;
		Combination(index + 1);
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> status[i][j];

	Combination(0);
	cout << result << endl;
	return 0;
}