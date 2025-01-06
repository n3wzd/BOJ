#include <iostream>
#include <algorithm>
using namespace std;

int N;
int clock1[200001];
int clock2[200001];
int T[400002];
int P[200001];
int pi[200001];
const int ANGLE_MAX = 360000;

void PI_Setting()
{
	int len = N;
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

bool KMP()
{
	int T_len = 2 * N, P_len = N;
	int begin = 0, window = 0;
	PI_Setting();

	while (begin <= T_len - P_len) {
		if (T[begin + window] == P[window] && window < P_len) {
			window++;
			if (window == P_len)
				return true;
		}
		else {
			if (window > 0) {
				begin += window - pi[window - 1];
				window = pi[window - 1];
			}
			else begin++;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) cin >> clock1[i];
	for (int i = 0; i < N; i++) cin >> clock2[i];
	sort(clock1, clock1 + N);
	sort(clock2, clock2 + N);

	for (int i = 0; i < N; i++) {
		T[i] = (clock1[(i + 1) % N] - clock1[i] + ANGLE_MAX) % ANGLE_MAX;
		P[i] = (clock2[(i + 1) % N] - clock2[i] + ANGLE_MAX) % ANGLE_MAX;
	}
	for (int i = N; i < N * 2; i++)
		T[i] = T[i - N];

	if (KMP()) cout << "possible";
	else cout << "impossible";
	return 0;
}
