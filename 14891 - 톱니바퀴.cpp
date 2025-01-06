#include <iostream>
using namespace std;
int K, G[4][8] = { 0, }, S = 0;

void rotate(int id, int dire) {
	int tmp = G[id][0], t = 8;
	for (int i = 0; i < 7; i += 1) {
		G[id][t % 8] = G[id][(t - dire) % 8];
		t -= dire;
	}
	G[id][(8 + dire) % 8] = tmp;
}

bool check(int a, int b) {
	return G[a][2] != G[b][6];
}

int inverse(int dire, bool filter) {
	return filter ? dire : (dire == 1) ? -1 : 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 4; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < 8; j++)
			G[i][j] = str[j] == '0' ? 0 : 1;
	}
	cin >> K;
	while (K--) {
		int id, dire;
		bool flag[4] = { 0, };
		cin >> id >> dire; id--;
		flag[id] = true;

		for (int i = id; i < 3; i++) {
			flag[i + 1] = check(i, i + 1);
			if (!flag[i + 1])
				break;
		}
		for (int i = id; i >= 1; i--) {
			flag[i - 1] = check(i - 1, i);
			if (!flag[i - 1])
				break;
		}
		for (int i = 0; i < 4; i++)
			if (flag[i])
				rotate(i, inverse(dire, abs(id - i) % 2 == 0));
	}
	for (int i = 0; i < 4; i++)
		S += G[i][0] << i;
	cout << S;
	return 0;
}
