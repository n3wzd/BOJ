#include <iostream>
using namespace std;

class Point {
public:
	int x, y;
	Point() { x = 0, y = 0; }
	Point(int a, int b) { x = a, y = b; }
};

int N, W;
Point work[1002];
int cache[1002][1002];
int trace[1002][1002];

int WorkDistance(Point p1, Point p2) {
	return abs(p1.x - p2.x) + abs(p1.y - p2.y);
}

int DP(int car1, int car2)
{
	if (car1 >= W || car2 >= W) return 0;
	if (trace[car1][car2] != 0) return cache[car1][car2];
	
	int inc = max(car1, car2) + 1;
	Point prePos1 = (car1 >= 1) ? work[car1] : Point(1, 1);
	Point prePos2 = (car2 >= 1) ? work[car2] : Point(N, N);
	int cost1 = WorkDistance(work[inc], prePos1) + DP(inc, car2);
	int cost2 = WorkDistance(work[inc], prePos2) + DP(car1, inc);

	cache[car1][car2] = min(cost1, cost2);
	trace[car1][car2] = (cost1 <= cost2) ? 1 : 2;
	return cache[car1][car2];
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> W;
	for (int i = 1; i <= W; i++)
		cin >> work[i].x >> work[i].y;
	cout << DP(0, 0) << "\n";

	int car1 = 0, car2 = 0;
	for (int i = 1; i <= W; i++)
	{
		cout << trace[car1][car2] << "\n";
		if (trace[car1][car2] == 1) car1 = i;
		else car2 = i;
	}
	return 0;
}
