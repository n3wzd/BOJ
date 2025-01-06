#include <iostream>
using namespace std;
const int MOD = 9901, SIZE = (1 << 14) + 5;
int N, M;
int cache[14][SIZE];
bool visited[14][SIZE];
int MA(int n1, int n2) { return ((n1 % MOD) + (n2 % MOD)) % MOD; }
int DPSub(int y, int field, int x, int nextField);
int DP(int y, int field);

int DPSub(int y, int field, int x, int nextField) {
	while (field & (1 << x)) x++;
	if (x > M)
		return 0;
	if (x == M)
		return DP(y + 1, nextField);

	int sum = DPSub(y, field, x + 1, nextField | (1 << x));
	if (!(field & (1 << (x + 1))))
		sum = MA(sum, DPSub(y, field, x + 2, nextField));
	return sum;
}

int DP(int y, int field) {
	if (y == N)
		return (field == 0) ? 1 : 0;
	if(visited[y][field])
		return cache[y][field];

	cache[y][field] = DPSub(y, field, 0, 0);
	visited[y][field] = 1;
	return cache[y][field];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	if ((N * M) % 2 == 1) {
		cout << 0;
		return 0;
	}
	cout << DP(0, 0);
	return 0;
}
