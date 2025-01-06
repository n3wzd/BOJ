#include <iostream>
#include <cmath>
typedef long long ll;
using namespace std;

int N, K, FS = 0;
string numset[15];
int mod_num[15], mod_power[651] = { 1, 0 };
ll cache[1 << 15][100];
bool visited[1 << 15][100];

int Mod(string num)
{
	int mod_sum = 0, power = 1;
	for (int i = num.size() - 1; i >= 0; i--)
	{
		mod_sum = (mod_sum + ((num[i] - '0') * power) % K) % K;
		power = (power * 10) % K;
	}
	return mod_sum;
}

ll DP(int list, int rem, int num_len)
{
	if (list == (1 << N) - 1) return (rem == 0) ? 1 : 0;
	if (visited[list][rem]) return cache[list][rem];

	for (int i = 0; i < N; i++)
		if (!(list & (1 << i)))
			cache[list][rem] += DP(list | (1 << i), (rem + mod_num[i] * mod_power[num_len - numset[i].size()]) % K, num_len - numset[i].size());

	visited[list][rem] = 1;
	return cache[list][rem];
}

ll Factorial(ll n)
{
	if (n <= 1) return 1;
	return n * Factorial(n - 1);
}

ll GCD(ll a, ll b)
{
	return (a % b == 0) ? b : GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> numset[i];
		FS += numset[i].size();
	}
	cin >> K;

	for (int i = 0; i < N; i++) mod_num[i] = Mod(numset[i]);
	for (int i = 1; i <= FS; i++) mod_power[i] = (mod_power[i - 1] * (10 % K)) % K;

	DP(0, 0, FS);
	ll gcd = GCD(cache[0][0], Factorial(N));

	if (cache[0][0] == 0) cout << "0/1";
	else cout << cache[0][0] / gcd << "/" << Factorial(N) / gcd;
	return 0;
}