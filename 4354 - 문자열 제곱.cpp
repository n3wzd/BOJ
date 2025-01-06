#include <iostream>
#include <memory.h>
using namespace std;

string P;
int pi[1000001];

int Failure()
{
	int len = P.size();
	int begin = 1, window = 0;
	memset(pi, 0, sizeof(int) * len);

	while (begin < len) {
		if (P[begin + window] == P[window]) {
			window++;
			pi[begin + window - 1] = window;
		}
		else {
			if (window > 0) {
				begin += window - pi[window - 1];
				window = pi[window - 1];
			}
			else begin++;
		}
	}

	int fix = pi[len - 1];
	if (fix == 0) return 1;
	else if (fix % (len - fix) == 0) return len / (len - fix);
	else return 1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (1) {
		cin >> P;
		if (P == ".") break;
		cout << Failure() << "\n";
	}
	return 0;
}