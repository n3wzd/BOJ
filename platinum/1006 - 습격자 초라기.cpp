#include <iostream>
using namespace std;

int N, W;
int cache[10001][2][3];
int enemy[10001][2];
int circular = 0;
const int _MAX = 99999;

int DP(int s, int ot, int diff)
{
	if (s >= N) return 0;
	if (s == N - 1)
	{
		if (circular == 0) {
			if (diff == 0) return (enemy[s][ot] + enemy[s][(ot + 1) % 2] <= W) ? 1 : 2;
			else if (diff == 1) return 1;
			else return _MAX;
		}
		else if (circular == 3) return 0;
		else return _MAX;
	}
	if (s == N - 2 && circular != 0) {
		if (circular == 3) {
			if (diff == 0) return (enemy[s][ot] + enemy[s][(ot + 1) % 2] <= W) ? 1 : 2;
			else if (diff == 1) return 1;
			else return _MAX;
		}
		else {
			int wall = (circular + 1) % 2;
			if (ot == wall && diff == 1) return 2;
			else if (ot != wall && diff == 1) return (enemy[s][ot] + enemy[s + 1][ot] <= W) ? 1 : 2;
			else if (ot == wall && diff == 0)
				return ((enemy[s][(ot + 1) % 2] + enemy[s + 1][(ot + 1) % 2] <= W) || (enemy[s][ot] + enemy[s][(ot + 1) % 2] <= W)) ? 2 : 3;
			else if (ot != wall && diff == 0)
				return ((enemy[s][ot] + enemy[s + 1][ot] <= W) || (enemy[s][ot] + enemy[s][(ot + 1) % 2] <= W)) ? 2 : 3;
			else return _MAX;
		}
	}
	if (cache[s][ot][diff] > 0) return cache[s][ot][diff];

	cache[s][ot][diff] = 1;
	bool con1 = (enemy[s][ot] + enemy[s + 1][ot]) <= W;
	bool con2 = (enemy[s][ot] + enemy[s][(ot + 1) % 2]) <= W;

	if (diff == 0)
	{
		int block1 = DP(s, (ot + 1) % 2, 1);
		int block2 = DP(s + 1, ot, 0);
		int block3 = DP(s, (ot + 1) % 2, 2);

		if (con1 && con2) cache[s][ot][diff] += min(block1, min(block2, block3));
		else if (con1) cache[s][ot][diff] += min(block1, block3);
		else if (con2) cache[s][ot][diff] += min(block1, block2);
		else cache[s][ot][diff] += block1;
	}
	else if (diff == 1)
	{
		int block1 = DP(s + 1, ot, 0);
		int block2 = DP(s + 1, (ot + 1) % 2, 1);

		if (con1) cache[s][ot][diff] += min(block1, block2);
		else cache[s][ot][diff] += block1;
	}
	else if (diff == 2)
	{
		int block1 = DP(s + 1, ot, 1);
		int block2 = DP(s + 2, ot, 0);

		if (con1) cache[s][ot][diff] += min(block1, block2);
		else cache[s][ot][diff] += block1;
	}
	return cache[s][ot][diff];
}

void Setting(int c)
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 2; j++)
			for (int w = 0; w < 3; w++)
				cache[i][j][w] = 0;
	circular = c;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> N >> W;
		for (int j = 0; j < 2; j++)
			for (int i = 0; i < N; i++)
				cin >> enemy[i][j];

		int batch = _MAX;
		for (int c = 0; c < 4; c++)
		{
			Setting(c);
			int data = _MAX;
			bool con1 = (enemy[0][0] + enemy[N - 1][0]) <= W;
			bool con2 = (enemy[0][1] + enemy[N - 1][1]) <= W;
			if (c == 0) data = DP(0, 0, 0);
			if (c == 1 && con1) data = DP(0, 1, 1) + 1;
			if (c == 2 && con2) data = DP(0, 0, 1) + 1;
			if (c == 3 && con1 && con2) data = DP(1, 0, 0) + 2;
			batch = min(batch, data);
		}
		cout << batch << "\n";
	}
	return 0;
}
