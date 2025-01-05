#include <iostream>
#include <set>
using namespace std;
int maps[1001][1001], parent[1003], N;
set<int> groups;

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

void Paint(int x, int y, int i) {
	if (maps[y][x] > 0)
		Union(maps[y][x], i);
	maps[y][x] = i;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i <= N + 1; i++)
		parent[i] = -1;
	for (int i = 1; i <= N; i++) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1 += 500, y1 += 500, x2 += 500, y2 += 500;
		for (int x = x1; x <= x2; x++)
			Paint(x, y1, i), Paint(x, y2, i);
		for (int y = y1; y <= y2; y++)
			Paint(x1, y, i), Paint(x2, y, i);
	}
	if (maps[500][500] > 0)
		Union(maps[500][500], N + 1);
	for (int i = 1; i <= N + 1; i++)
		groups.insert(Find(i));
	cout << groups.size() - 1;
	return 0;
}
