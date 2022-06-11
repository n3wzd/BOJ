#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
class Circle {
public:
	int x, r, gauge = 0;
};
int N, sum = 1;
Circle C[300001];
stack<Circle*> stk;

bool cmp(Circle a, Circle b) {
	return (a.x - a.r) != (b.x - b.r) ? (a.x - a.r) < (b.x - b.r) : a.r > b.r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> C[i].x >> C[i].r;
	sort(C, C + N, cmp);
	sum += N;

	stk.push(&C[0]);
	for (int i = 1; i < N; i++) {
		while (!stk.empty()) {
			Circle* T = stk.top();
			if (T->x - T->r + T->gauge == C[i].x - C[i].r) {
				T->gauge += C[i].r * 2;
				if (T->gauge == T->r * 2) {
					sum++;
					stk.pop();
				}
				break;
			}
			else if (T->x - T->r + T->gauge < C[i].x - C[i].r) stk.pop();
			else break;
		}
		stk.push(&C[i]);
	}
	cout << sum;
	return 0;
}
