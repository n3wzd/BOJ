#include <iostream>
using namespace std;
typedef long long ll;
struct Line { ll a, b; int id; }; // y = ax + b
const int SIZE = 1e5 + 2, SIZE2 = 202;
ll X[SIZE], cache[2][SIZE];
int N, K, trace[SIZE2][SIZE];

struct CHT {
	int bot, top = 0;
	Line deq[SIZE];
	ll GetValue(int lo, ll x) { return deq[lo].a * x + deq[lo].b; }
	void Clear() { top = bot = 0; }

	double Cross(int L1, int L2) {
		return (double)(deq[L1].b - deq[L2].b) / (deq[L2].a - deq[L1].a);
	}

	void Insert(Line v) {
		if ((top - bot) < 1) {
			deq[top++] = v;
			return;
		}
		if (v.a == deq[top - 1].a)
			top--;

		deq[top] = v;
		while (1 < (top - bot) && Cross(top - 2, top - 1) > Cross(top - 1, top)) {
			deq[top - 1] = deq[top];
			top--;
		}
		top++;
	}

	int Search(ll x) {
		while (1 < (top - bot) && deq[bot + 1].b - deq[bot].b >= x * (deq[bot].a - deq[bot + 1].a))
			bot++;
		return bot;
	}
};
CHT cht;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		ll x; cin >> x;
		X[i] = X[i - 1] + x;
	}

	for (int k = 1; k <= K; k++) {
		int m = k % 2;
		cht.Clear();
		cht.Insert({ X[1], -X[1] * X[1], 1 });
		for (int i = 2; i <= N; i++) {
			int lo = cht.Search(X[i]);
			cache[m][i] = cht.GetValue(lo, X[i]);
			trace[k][i] = cht.deq[lo].id;
			cht.Insert({ X[i], -X[i] * X[i] + cache[(m + 1) % 2][i], i });
		}
	}
	cout << cache[K % 2][N] << "\n";

	int tsk[SIZE2] = { trace[K][N] };
	for (int k = 1; k < K; k++)
		tsk[k] = trace[K - k][tsk[k - 1]];
	for (int k = K - 1; k >= 0; k--)
		cout << tsk[k] << " ";
	return 0;
}
