#include <iostream>
using namespace std;
int N;
int dial[10002], goal[10002];
int cache[10002][10];
bool visited[10002][10];
const int INF = 1 << 29;

int DP(int n, int spin) {
	if (n == N)
		return 0;
	if (visited[n][spin])
		return cache[n][spin];

	cache[n][spin] = INF;
	for (int L = 0; L < 10; L++) {
		int cur = (dial[n] + (spin + L)) % 10;
		int R = (cur - goal[n] + 10) % 10;
		cache[n][spin] = min(cache[n][spin], DP(n + 1, (spin + L) % 10) + L + R);
	}
	visited[n][spin] = 1;
	return cache[n][spin];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		dial[i] = c - '0';
	}
	for (int i = 0; i < N; i++) {
		char c;
		cin >> c;
		goal[i] = c - '0';
	}
	cout << DP(0, 0);
	return 0;
}
