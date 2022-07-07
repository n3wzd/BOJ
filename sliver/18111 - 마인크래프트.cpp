#include <iostream>
using namespace std;
int N, M, B;
int block = 0, space = 0;
int H[258];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> B;
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			int h;
			cin >> h;
			H[h]++;
			block += h;
		}
	}
	
	int time = 1 << 30, workH = 0, layer = N * M;
	for (int h = 0; h <= 256; h++) {
		int workTime = 2 * block + space;
		if (block + B >= space && workTime <= time) {
			time = workTime;
			workH = h;
		}

		layer -= H[h];
		block -= layer;
		space += (N * M) - layer;
	}

	cout << time << " " << workH;
	return 0;
}
