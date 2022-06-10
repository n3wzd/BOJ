#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
typedef long long ll;
using namespace std;
class Point {
public:
	int x = 0, y = 0;
	ll leftBig = 0, rightBig = 0;
	Point() { }
	Point(int a, int b) { x = a, y = b; }
};
int tree[1600008];
Point star[200002];
vector<int> Y;
const int MAXV = 400001;
const ll P = 1000000007;

bool cmp(Point a, Point b) {
	return (a.x != b.x) ? a.x < b.x : a.y < b.y;
}

int TreeGet(int start, int end, int idx, int left, int right) {
	if (start > right || end < left) return 0;
	if (start >= left && end <= right) return tree[idx];
	int mid = (start + end) / 2;
	return TreeGet(start, mid, idx * 2, left, right) + TreeGet(mid + 1, end, idx * 2 + 1, left, right);
}

int TreeUpdate(int start, int end, int idx, int pos, int diff) {
	if (start > pos || end < pos) return tree[idx];
	if (start == end) return tree[idx] += diff;
	int mid = (start + end) / 2;
	return tree[idx] = TreeUpdate(start, mid, idx * 2, pos, diff) + TreeUpdate(mid + 1, end, idx * 2 + 1, pos, diff);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	ll sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> star[i].x >> star[i].y;
		Y.push_back(star[i].y);
	}
	sort(star, star + N, cmp);

	sort(Y.begin(), Y.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++)
		star[i].y = lower_bound(Y.begin(), Y.end(), star[i].y) - Y.begin();

	int preX = N - 1;
	for (int i = N - 1; i >= 0; i--) {
		star[i].rightBig = TreeGet(0, MAXV, 1, star[i].y + 1, MAXV);
		if (i > 0) {
			if (star[i].x != star[i - 1].x) {
				for (int w = preX; w >= i; w--)
					TreeUpdate(0, MAXV, 1, star[w].y, 1);
				preX = i - 1;
			}
		}
	}
	
	preX = 0;
	memset(tree, 0, sizeof(tree));
	for (int i = 0; i < N; i++) {
		star[i].leftBig = TreeGet(0, MAXV, 1, star[i].y + 1, MAXV);
		if(i < N - 1) {
			if (star[i].x != star[i + 1].x) {
				for (int w = preX; w <= i; w++)
					TreeUpdate(0, MAXV, 1, star[w].y, 1);
				preX = i + 1;
			}
		}
		sum = (sum + (star[i].leftBig * star[i].rightBig) % P) % P;
	}

	cout << sum;
	return 0;
}
