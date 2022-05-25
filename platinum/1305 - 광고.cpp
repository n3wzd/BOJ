#include <iostream>
using namespace std;

string P;
int pi[1000001];

int Failure()
{
	int len = P.size();
	int begin = 1, window = 0;

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
	return len - fix;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N >> P;
	cout << Failure() << "\n";
	return 0;
}
