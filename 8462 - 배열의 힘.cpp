#include <iostream>
#include <cmath>
#include <algorithm>
typedef long long ll;
using namespace std;
int N, sqN, M;
ll res = 1;
ll arr[100001], resList[100001];
ll cnt[1000001];

class Query {
public:
	int left, right, order;
	Query() {}
	Query(int a, int b, int c) { left = a, right = b, order = c; }
};
Query query[100001];

bool cmp(Query a, Query b) {
	return (a.right / sqN != b.right / sqN) ? a.right / sqN < b.right / sqN : a.left < b.left;
}

ll PWR(ll n) {
	return cnt[n] * cnt[n] * n;
}

void Scan(int p, int d) {
	ll n = arr[p];
	res -= PWR(n);
	cnt[arr[p]] += d;
	res += PWR(n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	sqN = sqrt(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	for (int i = 0; i < M; i++) {
		cin >> query[i].left >> query[i].right;
		query[i].left--, query[i].right--, query[i].order = i;
	}
	sort(query, query + M, cmp);

	int lo = query[0].left;
	int hi = lo;
	cnt[arr[lo]] = 1;
	res = PWR(arr[lo]);
	for (int i = 0; i < M; i++) {
		int newLo = query[i].left, newHi = query[i].right;
		while (lo > newLo) Scan(--lo, 1);
		while (lo < newLo) Scan(lo++, -1);
		while (hi < newHi) Scan(++hi, 1);
		while (hi > newHi) Scan(hi--, -1);
		resList[query[i].order] = res;
	}
	for (int i = 0; i < M; i++)
		cout << resList[i] << "\n";

	return 0;
}
