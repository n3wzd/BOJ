#include <iostream>
typedef long long ll;
using namespace std;

ll N;
int dice[6];

int Min5()
{
	int sum = 0, maxv = 0;
	for (int i = 0; i < 6; i++) {
		sum += dice[i];
		maxv = max(maxv, dice[i]);
	}
	return sum - maxv;
}

int Min1()
{
	int minv = 99999;
	for (int i = 0; i < 6; i++)  minv = min(minv, dice[i]);
	return minv;
}

int Min2()
{
	int minv = 99999;
	for (int i = 0; i < 4; i++) minv = min(minv, dice[0] + dice[i + 1]);
	for (int i = 0; i < 4; i++) minv = min(minv, dice[5] + dice[i + 1]);
	for (int i = 0; i < 2; i++) minv = min(minv, dice[1] + dice[i + 2]);
	for (int i = 0; i < 2; i++) minv = min(minv, dice[4] + dice[i + 2]);
	return minv;
}

int Min3()
{
	int minv = 99999;
	for (int k = 0; k < 2; k++)
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
				minv = min(minv, dice[k * 5] + dice[1 + i * 3] + dice[2 + j]);
	return minv;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < 6; i++) cin >> dice[i];

	ll m1 = Min1(), m2 = Min2(), m3 = Min3();
	if (N == 1) cout << Min5();
	else if (N == 2) {
		ll d2 = m2 * 4;
		ll d3 = m3 * 4;
		cout << d2 + d3;
	}
	else {
		ll d1 = m1 * (((N - 2) * (N - 2) * 5) + (N - 2) * 4);
		ll d2 = m2 * ((N - 2) * 8 + 4);
		ll d3 = m3 * 4;
		cout << d1 + d2 + d3;
	}
	return 0;
}
