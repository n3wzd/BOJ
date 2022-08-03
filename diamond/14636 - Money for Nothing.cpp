#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
struct Company { ll p, d; };
const int SIZE = 5e5 + 2;
int N, M; ll res = 0;
Company P[SIZE], C[SIZE];
vector<Company> PS, CS;
ll F(ll i, ll j) { return (CS[i].d - PS[j].d) * (CS[i].p - PS[j].p); }
bool cmp(Company a, Company b) { return a.d < b.d; }

void DC(ll lo, ll hi, ll lo2, ll hi2) {
	if (lo > hi)
		return;
	ll i = (lo + hi) / 2;
	ll v = -2e18, v_idx = lo2;

	for (int j = lo2; j <= hi2; j++) {
		if (PS[j].d >= CS[i].d) break;
		if (F(i, j) >= v) {
			v = F(i, j);
			v_idx = j;
		}
	}
	res = max(res, v);

	DC(lo, i - 1, lo2, v_idx);
	DC(i + 1, hi, v_idx, hi2);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		cin >> P[i].p >> P[i].d;
	for (int i = 0; i < N; i++)
		cin >> C[i].p >> C[i].d;
	sort(P, P + M, cmp);
	sort(C, C + N, cmp);

	PS.push_back(P[0]); CS.push_back(C[0]);
	for (int i = 1; i < M; i++)
		if (PS.back().p > P[i].p)
			PS.push_back(P[i]);
	for (int i = 1; i < N; i++) {
		while (!CS.empty() && CS.back().p <= C[i].p)
			CS.pop_back();
		CS.push_back(C[i]);
	}

	DC(0, CS.size() - 1, 0, PS.size() - 1);
	cout << res;
	return 0;
}
