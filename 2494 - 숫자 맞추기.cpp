#include <iostream>
using namespace std;
struct TRC { int L, localL, R; };
int N;
int dial[10002], goal[10002];
int cache[10002][10];
TRC trace[10002][10];
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

		int next = DP(n + 1, (spin + L) % 10) + L + R;
		if (cache[n][spin] > next) {
			cache[n][spin] = next;
			trace[n][spin] = { (spin + L) % 10, L, R };
		}
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
	cout << DP(0, 0) << "\n";

	for (int n = 0, spin = 0; n < N; n++) {
		TRC t = trace[n][spin];
		cout << n + 1 << " " << t.localL - t.R << "\n";
		spin = t.L;
	}
	return 0;
}
