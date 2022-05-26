#include <iostream>
using namespace std;
int tilemap[129][129];
int tile_id = 1, power, N, drain_x, drain_y;

void TileMaker(int x, int y, int non_x, int non_y) {
	for (int dy = 0; dy < 2; dy++)
		for (int dx = 0; dx < 2; dx++)
			if ((x + dx != non_x || y + dy != non_y) && tilemap[y + dy][x + dx] == 0)
				tilemap[y + dy][x + dx] = tile_id;
	tile_id++;
}

void Drain(int x, int y, int p, int non_x, int non_y) {
 	if (p <= 2) {
		TileMaker(x, y, non_x, non_y);
		return;
	}

	int np = p / 2;
	for (int i = 0; i < 4; i++) {
		int nx, ny, nnon_x, nnon_y;
		if (i == 0) {
			nx = x, ny = y;
			nnon_x = x + np - 1, nnon_y = y + np - 1;
		}
		if (i == 1) {
			nx = x + np, ny = y;
			nnon_x = x + np, nnon_y = y + np - 1;
		}
		if (i == 2) {
			nx = x, ny = y + np;
			nnon_x = x + np - 1, nnon_y = y + np;
		}
		if (i == 3) {
			nx = x + np, ny = y + np;
			nnon_x = x + np, nnon_y = y + np;
		}
		if (non_x >= nx && non_x < nx + np && non_y >= ny && non_y < ny + np)
			nnon_x = non_x, nnon_y = non_y;

		Drain(nx, ny, np, nnon_x, nnon_y);
	}

	TileMaker(x + np - 1, y + np - 1, -1, -1);
}

void Print() {
	tilemap[drain_y][drain_x] = -1;
	for (int y = N - 1; y >= 0; y--) {
		for (int x = 0; x < N; x++)
			cout << tilemap[y][x] << " ";
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> power >> drain_x >> drain_y;
	Drain(0, 0, N = (1 << power), --drain_x, --drain_y);
	Print();
	return 0;
}
