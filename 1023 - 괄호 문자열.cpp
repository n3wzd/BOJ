#include <iostream>
typedef long long ll;
using namespace std;

int N;
ll K;
ll cache[51][2][51];
bool visited[51][2][51];

ll DP(int n, int b, int life)
{
	if (life < 0) return 0;
	if (n == N - 1) return (life == 0) ? 1 : 0;
	if (visited[n][b][life]) return cache[n][b][life];

	cache[n][b][life] = DP(n + 1, 0, life + 1) + DP(n + 1, 1, life - 1);
	visited[n][b][life] = 1;
	return cache[n][b][life];
}

ll Finder(int n, ll k, int life)
{
	if (n == N) return (life == 0) ? 1 : 0;
	ll sum = 0;
	if (k & ((ll)1 << ((N - 1) - n))) {
		if (life > 0) sum = cache[n][0][life + 1] + Finder(n + 1, k, life - 1);
		else sum = cache[n][0][1];
	}
	else sum = Finder(n + 1, k, life + 1);
	return sum;
}

void Printer(int n, ll k)
{
	if (n == N) return;
	if (k & ((ll)1 << ((N - 1) - n))) cout << ")";
	else cout << "(";
	Printer(n + 1, k);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	DP(0, 0, 1);

	ll newK = K, preKF = 0;
	while (1)
	{
		ll newKF = Finder(0, newK, 0);
		newK += newKF - preKF;
		if (newKF - preKF <= 0 || newK >= ((ll)1 << N)) break;
		preKF = newKF;
	}

	if (newK < ((ll)1 << N)) Printer(0, newK);
	else cout << "-1";
	return 0;
}
