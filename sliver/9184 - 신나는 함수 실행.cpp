#include <iostream>
using namespace std;

class Node
{
public:
	int a, b, c, r;

	void Set(int a, int b, int c, int r)
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->r = r;
	}

	void Print()
	{
		printf("w(%d, %d, %d) = %d\n", a, b, c, r);
	}
};

Node node[10000];
int len = 0;
int memoi[21][21][21] = { 0, };
bool memoi_ck[21][21][21] = { 0, };

int W(int a, int b, int c)
{
	int num;
	if (a <= 0 || b <= 0 || c <= 0) { return 1; }
	else if (a > 20 || b > 20 || c > 20) { return W(20, 20, 20); } // prevent to Out of Bounds

	if (memoi_ck[a][b][c]) return memoi[a][b][c]; // memoization

	if (a < b && b < c) num = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c);
	else num = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);

	memoi[a][b][c] = num;
	memoi_ck[a][b][c] = true;
	return num;
}

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		node[len].Set(a, b, c, W(a, b, c));
		len++;
	}

	for (int i = 0; i < len; i++)
		node[i].Print();

	return 0;
}