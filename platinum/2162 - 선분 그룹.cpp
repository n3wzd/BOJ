#include <iostream>
#include <cmath>
using namespace std;

typedef struct Point {
	int x, y;
} Point;

typedef struct Line {
	Point p1, p2;
} Line;

int N, set_cnt = 0, set_max = 0;
Line line[3002];
int parent[3002];

int CCW(Point a, Point b, Point c)
{
	int D = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
	return (D == 0) ? 0 : ((D > 0) ? 1 : -1);
}

int Cross(Line l1, Line l2)
{
	Point p1 = l1.p1, p2 = l1.p2, p3 = l2.p1, p4 = l2.p2;
	int r1 = CCW(p1, p2, p3), r2 = CCW(p1, p2, p4);
	int r3 = CCW(p3, p4, p1), r4 = CCW(p3, p4, p2);
	int res;

	if (r1 == 0 || r2 == 0 || r3 == 0 || r4 == 0)
	{
		if (r1 == 0 && r2 == 0 && r3 == 0 && r4 == 0)
		{
			int ranx1 = min(p1.x, p2.x), ranx2 = max(p1.x, p2.x);
			int rany1 = min(p1.y, p2.y), rany2 = max(p1.y, p2.y);
			int ranx3 = min(p3.x, p4.x), ranx4 = max(p3.x, p4.x);
			int rany3 = min(p3.y, p4.y), rany4 = max(p3.y, p4.y);
			res = (p3.x >= ranx1 && p3.x <= ranx2 && p3.y >= rany1 && p3.y <= rany2) ||
				(p4.x >= ranx1 && p4.x <= ranx2 && p4.y >= rany1 && p4.y <= rany2) ||
				(p1.x >= ranx3 && p1.x <= ranx4 && p1.y >= rany3 && p1.y <= rany4) ||
				(p2.x >= ranx3 && p2.x <= ranx4 && p2.y >= rany3 && p2.y <= rany4);
		}
		else
		{
			if ((p1.x == p3.x && p1.y == p3.y) || (p1.x == p4.x && p1.y == p4.y) ||
				(p2.x == p3.x && p2.y == p3.y) || (p2.x == p4.x && p2.y == p4.y)) res = 1;
			else
				res = r1 != r2 && r3 != r4;
		}
	}
	else
		res = r1 != r2 && r3 != r4;
	return res;
}

int Find(int n)
{
	int p = n;
	while (parent[p] >= 0) p = parent[p];
	if (parent[n] >= 0) parent[n] = p;
	return p;
}

void Union(int a, int b)
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;

	if (parent[p1] < parent[p2])
	{
		parent[p1] += parent[p2];
		parent[p2] = p1;
	}
	else
	{
		parent[p2] += parent[p1];
		parent[p1] = p2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> line[i].p1.x >> line[i].p1.y >> line[i].p2.x >> line[i].p2.y;
	
	for (int i = 0; i <= N; i++)
		parent[i] = -1;

	for (int i = 0; i < N; i++)
		for (int j = i + 1; j < N; j++)
			if (Cross(line[i], line[j]) == 1)
				Union(i, j);
	
	for (int i = 0; i < N; i++)
	{
		if (parent[i] < 0)
		{
			set_max = max(set_max, -parent[i]);
			set_cnt++;
		}
	}

	cout << set_cnt << "\n" << set_max;
	return 0;
}
