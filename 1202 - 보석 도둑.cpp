#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
struct Jewel { int M, V; };
int N, K;
Jewel jewel[300002];
multiset<int> bag;
bool cmp(Jewel a, Jewel b) { return a.V > b.V; }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> K;
	for (int i = 0; i < N; i++)
		cin >> jewel[i].M >> jewel[i].V;
	for (int i = 0; i < K; i++) {
		int b;
		cin >> b;
		bag.insert(b);
	}
	sort(jewel, jewel + N, cmp);

	long long sum = 0;
	for (int i = 0; i < N; i++) {
		multiset<int>::iterator it = bag.lower_bound(jewel[i].M);
		if (it != bag.end()) {
			bag.erase(it);
			sum += jewel[i].V;
		}
	}
	cout << sum;
	return 0;
}
