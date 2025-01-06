#include <iostream>
using namespace std;
int N, K, pos, durable[202], broken, cnt = 1;
bool robot[202];
int getIdx(int i) { return (i + N * 2) % (N * 2); }

void harvest() {
	robot[getIdx(N - 1 + pos)] = false;
}

void sub_durable(int i) {
	durable[i]--;
	if (durable[i] <= 0)
		broken++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N * 2; i++)
		cin >> durable[i];

	while (true) {
		pos = getIdx(pos - 1);
		harvest();

		for (int i = N - 2; i >= 0; i--) {
			int cur = getIdx(i + pos), next = getIdx(i + pos + 1);
			if (robot[cur] && !robot[next] && durable[next] > 0) {
				robot[cur] = false, robot[next] = true;
				sub_durable(next);
			}
		}
		harvest();

		int first = getIdx(pos);
		if (durable[first] > 0) {
			robot[first] = true;
			sub_durable(first);
		}
		if (broken >= K)
			break;
		cnt++;
	}
	cout << cnt;
	return 0;
}
