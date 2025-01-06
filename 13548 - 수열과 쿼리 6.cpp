#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int N, sqN, M, res = 1;
int arr[100001], resList[100001];
int cnt[100001], cnt2[100001];

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

void Scan(int p, int d) {
	int n = arr[p];
	cnt2[cnt[n]]--;
	cnt[n] += d;
	cnt2[cnt[n]]++;
	if (d > 0) res = max(res, cnt[n]);
	else if (cnt[n] + 1 == res && cnt2[cnt[n] + 1] == 0) res--;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	sqN = sqrt(N);
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> query[i].left >> query[i].right;
		query[i].left--, query[i].right--, query[i].order = i;
	}
	sort(query, query + M, cmp);

	int lo = query[0].left;
	int hi = lo;
	cnt[arr[lo]] = 1, cnt2[1] = 1, res = 1;
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
