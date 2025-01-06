#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Rect {
public:
	int x1, x2, y1, y2;
	Rect (int a, int b, int c, int d) { x1 = a, x2 = b, y1 = c, y2 = d; }
};
class Range {
public:
	int lo, hi, id;
	Range(int a, int b, int c) { lo = a, hi = b, id = c; }
};
int N, stage = 0;
vector<Rect> rect;
vector<Range> xLine[100008];
vector<Range> yLine[100008];
vector<int> X, Y;
int parent[50008];
int area[50008];

bool cmp(Range a, Range b) {
	return a.lo < b.lo;
}

int Find(int n) {
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if (parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b) {
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2]) {
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else {
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

void Sweeping(vector<Range> line[]) {
	for (int x = 0; x <= N * 2; x++) {
		if (line[x].empty()) continue;

		sort(line[x].begin(), line[x].end(), cmp);
		stack<Range> stk;
		stk.push(line[x][0]);

		int len = line[x].size();
		for (int i = 1; i < len; i++) {
			while (!stk.empty()) {
				if (line[x][i].lo <= stk.top().hi) {
					Union(stk.top().id, line[x][i].id);
					break;
				}
				else stk.pop();
			}
			stk.push(line[x][i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, w, h;
		cin >> x1 >> y1 >> w >> h;
		rect.push_back(Rect(x1, x1 + w, y1, y1 + h));
		area[i] = w * h;
		X.push_back(x1), X.push_back(x1 + w);
		Y.push_back(y1), Y.push_back(y1 + h);
	}
	for (int i = 0; i < N; i++)
		parent[i] = -1;
	
	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	Y.erase(unique(Y.begin(), Y.end()), Y.end());
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		x1 = lower_bound(X.begin(), X.end(), rect[i].x1) - X.begin();
		x2 = lower_bound(X.begin(), X.end(), rect[i].x2) - X.begin();
		y1 = lower_bound(Y.begin(), Y.end(), rect[i].y1) - Y.begin();
		y2 = lower_bound(Y.begin(), Y.end(), rect[i].y2) - Y.begin();

		xLine[x1].push_back(Range(y1, y2, i));
		xLine[x2].push_back(Range(y1, y2, i));
		yLine[y1].push_back(Range(x1, x2, i));
		yLine[y2].push_back(Range(x1, x2, i));
	}
	Sweeping(xLine);
	Sweeping(yLine);

	for (int i = 0; i < N; i++) {
		int p = Find(i);
		if (p == i) {
			stage = max(stage, area[p]);
			continue;
		}
		area[p] += area[i];
		stage = max(stage, area[p]);
	}
	cout << stage;
	return 0;
}
