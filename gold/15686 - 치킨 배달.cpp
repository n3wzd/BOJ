#include <iostream>
#include <cmath> 
using namespace std;
struct Point { int x, y; };
const int INF = 999999;
int N, M, H, C, input, res = INF;
Point house[102], chicken[14];
bool deleted_chicken[14];

void chicken_dist() {
	int final_dist = 0;
	for (int h = 0; h < H; h++) {
		int dist = INF;
		for (int c = 0; c < C; c++) {
			if (deleted_chicken[c])
				continue;
			dist = min(dist, abs(chicken[c].x - house[h].x) + abs(chicken[c].y - house[h].y));
		}
		final_dist += dist;
	}
	res = min(res, final_dist);
}

void quest(int depth = 0, int start = 0) {
	if (depth >= C - M) {
		chicken_dist();
		return;
	}
	for (int c = start; c < C; c++) {
		deleted_chicken[c] = true;
		quest(depth + 1, c + 1);
		deleted_chicken[c] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < N; x++) {
			cin >> input;
			if (input == 1)
				house[H++] = { x, y };
			else if (input == 2)
				chicken[C++] = { x, y };
		}
	}
	quest(); cout << res;
	return 0;
}
