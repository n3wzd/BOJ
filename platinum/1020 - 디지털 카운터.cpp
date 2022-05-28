#include <iostream>
#include <string>
#include <memory.h>
#include <cmath>
using namespace std;
typedef long long ll;
int N, LED_num = 0;
bool DP_mode = 1;
int num[17];
int cache[17][150][2];
bool visited[17][150][2];
int LED[10] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 5 };
const int IMP = -1;

int DP(int p, int led, int st) {
	if (visited[p][led][st]) return cache[p][led][st];

	if (led > LED_num) return IMP;
	if (p == N) return (led == LED_num) ? 1 : IMP;

	cache[p][led][st] = IMP;
	int start = 0, end = 9;
	if (DP_mode) {
		start = (st) ? num[p] : 0;
		if (p == N - 1 && st) start++;
	}
	else {
		end = (st) ? num[p] : 9;
	}
	for (int i = end; i >= start; i--)
		if (DP(p + 1, led + LED[i], st && (i == num[p])) != IMP)
			cache[p][led][st] = i;

	visited[p][led][st] = 1;
	return cache[p][led][st];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	string line;
	cin >> line;
	N = line.size();
	for (int i = 0; i < N; i++) {
		num[i] = line[i] - '0';
		LED_num += LED[num[i]];
	}
	if (DP(0, 0, 1) == IMP) {
		DP_mode = 0;
		memset(cache, 0, sizeof(cache));
		memset(visited, 0, sizeof(visited));
		DP(0, 0, 1);
	}

	ll res = 0, src = stoll(line), max_num = pow(10, N);
	int led = 0, st = 1;
	for (int p = 0; p < N; p++) {
		int digit = cache[p][led][st];
		res += digit * pow(10, N - p - 1);
		led += LED[digit];
		st = (st && (digit == num[p]));
	}
	if (res == src) cout << max_num;
	else cout << ((res - src) + max_num) % max_num;
	return 0;
}
