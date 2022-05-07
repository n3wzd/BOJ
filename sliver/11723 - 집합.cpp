#include <iostream>
#include <memory.h>
#define _SIZE 22
using namespace std;

int N, param;
bool list[_SIZE];

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "add") {
			cin >> param;
			list[param] = 1;
		}
		if (cmd == "remove") {
			cin >> param;
			list[param] = 0;
		}
		if (cmd == "check") {
			cin >> param;
			cout << list[param] << "\n";
		}
		if (cmd == "toggle") {
			cin >> param;
			list[param] = !list[param];
		}
		if (cmd == "all") {
			memset(list, 1, _SIZE);
		}
		if (cmd == "empty") {
			memset(list, 0, _SIZE);
		}
	}
	return 0;
}
