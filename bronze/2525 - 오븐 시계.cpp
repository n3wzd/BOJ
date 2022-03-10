#include <iostream>
using namespace std;

int main()
{
	int h, m, a;
	cin >> h >> m >> a;
	m += a;
	h += m / 60;
	h %= 24;
	m %= 60;
	cout << h << " " << m;
	return 0;
}