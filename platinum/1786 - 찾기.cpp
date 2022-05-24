#include <iostream>
#include <string>
#include <vector>
using namespace std;

string T, P;
int pi[1000001];
vector<int> search;

void PI_Setting()
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
}

void KMP()
{
	int T_len = T.size(), P_len = P.size();
	int begin = 0, window = 0;
	PI_Setting();

	while (begin <= T_len - P_len) {
		if (T[begin + window] == P[window] && window < P_len) {
			window++;
			if (window == P_len)
				search.push_back(begin);
		}
		else {
			if (window > 0) {
				begin += window - pi[window - 1];
				window = pi[window - 1];
			}
			else begin++;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	getline(cin, T);
	getline(cin, P);
	KMP();

	int len = search.size();
	cout << len << "\n";
	for (int i = 0; i < len; i++)
		cout << search[i] + 1 << " ";
	return 0;
}