#include <iostream>
using namespace std;

int G, P, cnt = 0;
int airport[100001];
bool docking1 = 0, close = 0;

int Find(int n)
{
	int p = n;
	while (airport[p] >= 0) p = airport[p];
	if (airport[n] >= 0) airport[n] = p;
	return p;
}

void Union(int a, int b) // a < b
{
	int p1 = Find(a);
	int p2 = Find(b);
	if (p1 == p2) return;
	airport[p1] += airport[p2];
	airport[p2] = p1;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> G >> P;
	for (int i = 0; i <= G; i++)
		airport[i] = -1;

	for (int i = 0; i < P; i++) {
		int plane;
		cin >> plane;
		if (close) continue;

		int goal = Find(plane);
		if (goal == 1) {
			if (!docking1) docking1 = 1;
			else {
				close = 1;
				continue;
			}
		}
		else Union(goal - 1, goal);
		cnt++;
	}
	cout << cnt;
	return 0;
}
