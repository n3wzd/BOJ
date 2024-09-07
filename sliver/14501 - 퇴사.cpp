#include <iostream>
using namespace std;
int N, T[17], P[17], res[17] = { 0, };

int solve(int day) {
	if (day >= N)
		return 0;
	if (res[day] > 0)
		return res[day];
	res[day] = solve(day + 1);
	if (day + T[day] <= N)
		res[day] = max(res[day], solve(day + T[day]) + P[day]);
	return res[day];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> T[i] >> P[i];
	cout << solve(0);
	return 0;
}
