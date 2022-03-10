#include <iostream>
using namespace std;

int px1, px2, py1, py2;
int pxc2 = 0, pyc2 = 0;

int main()
{
	int x, y;
	cin >> x >> y;
	px1 = x, py1 = y;

	for (int i = 1; i < 3; i++)
	{
		cin >> x >> y;
		if (x != px1)
		{
			px2 = x;
			pxc2++;
		}
		if (y != py1)
		{
			py2 = y;
			pyc2++;
		}
	}

	if (pxc2 < 2) printf("%d ", px2);
	else printf("%d ", px1);
	if (pyc2 < 2) printf("%d\n", py2);
	else printf("%d ", py1);

	return 0;
}