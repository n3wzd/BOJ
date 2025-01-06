#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}
int N, pass = 0;
pair<int, int> A[500001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    stable_sort(A, A + N, cmp);
    for (int i = N - 1; i >= 0; i--) 
        pass = max(pass, A[i].second - i);
    cout << pass + 1;
	return 0;
}
