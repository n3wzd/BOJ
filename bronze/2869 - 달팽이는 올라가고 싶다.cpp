#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double a, b, v; // 1 �� b < a �� v �� 1,000,000,000
	cin >> a >> b >> v;
	cout << (int)(ceil((v - a) / (a - b)) + 1);
	return 0;
}