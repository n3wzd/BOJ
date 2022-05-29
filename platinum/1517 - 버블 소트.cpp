#include <iostream>
typedef long long ll;
using namespace std;
ll N, bubble = 0;
ll list[500001];
ll new_list[500001];

void Merge(ll start, ll end) {
	if (start == end) return;

	ll mid = (start + end) / 2;
	Merge(start, mid);
	Merge(mid + 1, end);

	ll p1 = start, p2 = mid + 1, len = 0;
	while (p1 <= mid && p2 <= end) {
		if (list[p1] > list[p2]) {
			new_list[len++] = list[p2++];
			bubble += mid - p1 + 1;
		}
		else
			new_list[len++] = list[p1++];
	}
	while (p1 <= mid) new_list[len++] = list[p1++];
	while (p2 <= end) new_list[len++] = list[p2++];

	for (ll i = 0; i < len; i++)
		list[i + start] = new_list[i];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (ll i = 0; i < N; i++)
		cin >> list[i];
	Merge(0, N - 1);
	cout << bubble;
	return 0;
}
