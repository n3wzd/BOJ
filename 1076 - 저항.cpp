#include <iostream>
using namespace std;

int main()
{
	string resist[3];
	for (int i = 0; i < 3; i++)
		cin >> resist[i];

	long long res1 = 1;
	if (resist[2] == "brown") res1 *= 10;
	if (resist[2] == "red") res1 *= 100;
	if (resist[2] == "orange") res1 *= 1000;
	if (resist[2] == "yellow") res1 *= 10000;
	if (resist[2] == "green") res1 *= 100000;
	if (resist[2] == "blue") res1 *= 1000000;
	if (resist[2] == "violet") res1 *= 10000000;
	if (resist[2] == "grey") res1 *= 100000000;
	if (resist[2] == "white") res1 *= 1000000000;
	long long res2 = res1;

	if (resist[0] == "black") res1 *= 0;
	if (resist[0] == "brown") res1 *= 10;
	if (resist[0] == "red") res1 *= 20;
	if (resist[0] == "orange") res1 *= 30;
	if (resist[0] == "yellow") res1 *= 40;
	if (resist[0] == "green") res1 *= 50;
	if (resist[0] == "blue") res1 *= 60;
	if (resist[0] == "violet") res1 *= 70;
	if (resist[0] == "grey") res1 *= 80;
	if (resist[0] == "white") res1 *= 90;

	if (resist[1] == "black") res2 *= 0;
	if (resist[1] == "brown") res2 *= 1;
	if (resist[1] == "red") res2 *= 2;
	if (resist[1] == "orange") res2 *= 3;
	if (resist[1] == "yellow") res2 *= 4;
	if (resist[1] == "green") res2 *= 5;
	if (resist[1] == "blue") res2 *= 6;
	if (resist[1] == "violet") res2 *= 7;
	if (resist[1] == "grey") res2 *= 8;
	if (resist[1] == "white") res2 *= 9;

	cout << res1 + res2 << endl;
	return 0;
}