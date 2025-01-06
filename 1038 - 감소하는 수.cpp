#include <iostream>
using namespace std;

int N;
int num[10];

void Print()
{
	for (int i = 0; i < 10; i++)
		if (num[i] != -1)
			cout << num[i];
}

void BT(int pos, int range)
{
	num[pos] = 9 - pos;
	for (int i = 9 - pos; i < range; i++)
	{
		if (N < 0) return;
		if (pos < 9)
		{
			BT(pos + 1, num[pos]);
			num[pos]++;
		}
		else
		{
			if (N == 0) Print();
			num[pos]++,	N--;
		}
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < 10; i++) num[i] = -1;
	for (int i = 9; i >= 0; i--) BT(i, 10);
	if (N >= 0) cout << -1;
	return 0;
}