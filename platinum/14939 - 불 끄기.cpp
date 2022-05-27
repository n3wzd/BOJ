#include <iostream>
using namespace std;
const int LIGHT_MAX = 101;

int light_time = 0, light_min = LIGHT_MAX;
bool bulbmap[11][11];
bool simul[11][11];
int dx[5] = { 0, 1, 0, -1 ,0 };
int dy[5] = { 0, 0, 1, 0 ,-1 };

void Copy() {
	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 10; x++)
			simul[y][x] = bulbmap[y][x];
}

bool Blackout() {
	for (int y = 0; y < 10; y++)
		for (int x = 0; x < 10; x++)
			if (simul[y][x]) return 0;
	return 1;
}

void Light_Out(int x, int y) {
	for (int d = 0; d < 5; d++) {
		int nx = x + dx[d], ny = y + dy[d];
		if (nx < 0 || nx >= 10 || ny < 0 || ny >= 10) continue;
		simul[ny][nx] = !simul[ny][nx];
	}
	light_time++;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int y = 0; y < 10; y++) {
		string line;
		cin >> line;
		for (int x = 0; x < 10; x++)
			bulbmap[y][x] = (line[x] == 'O') ? 1 : 0;
	}

	for (int i = 0; i < (1 << 10); i++) {
		light_time = 0;
		Copy();

		for (int x = 0; x < 10; x++)
			if (i & (1 << x))
				Light_Out(x, 0);

		for (int y = 1; y < 10; y++)
			for (int x = 0; x < 10; x++)
				if(simul[y - 1][x])
					Light_Out(x, y);

		if (Blackout())
			light_min = min(light_min, light_time);
	}

	if (light_min != LIGHT_MAX) cout << light_min;
	else cout << -1;
	return 0;
}
