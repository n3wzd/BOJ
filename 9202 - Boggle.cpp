#include <iostream>
#include <memory.h>
using namespace std;

int N, T;
string dict[300001];
char boggle[4][4];
bool visited[4][4];
int dx[8] = { 1, 0, -1, 0, 1, 1, -1, -1 };
int dy[8] = { 0, 1, 0, -1, 1, -1, 1, -1 };
int AC[9] = { 0, 0, 0, 1, 1, 2, 3, 5, 11 };
bool find_ok = 0;

void BT(int x, int y, const char* str) {
	if (!*str) {
		find_ok = 1;
		return;
	}
	visited[y][x] = 1;

	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i], ny = y + dy[i];

		if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4) continue;
		if (visited[ny][nx]) continue;

		if (boggle[ny][nx] == *str)
			BT(nx, ny, str + 1);
	}
	visited[y][x] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> dict[i];

	cin >> T;
	while (T--) {
		for (int y = 0; y < 4; y++) {
			string line;
			cin >> line;
			for (int x = 0; x < 4; x++)
				boggle[y][x] = line[x];
		}

		string max_str;
		int max_strlen = 0;
		int score = 0;
		int word_cnt = 0;

		for (int n = 0; n < N; n++) {
			memset(visited, 0, sizeof(visited));
			const char* str = dict[n].c_str();
			find_ok = 0;

			for (int y = 0; y < 4; y++)
				for (int x = 0; x < 4; x++)
					if (*str == boggle[y][x])
						BT(x, y, str + 1);

			if (find_ok) {
				int len = dict[n].size();
				score += AC[len];
				if (max_strlen < len || (max_strlen == len && dict[n] < max_str)) {
					max_str = dict[n];
					max_strlen = len;
				}
				word_cnt++;
			}
		}
		cout << score << " " << max_str << " " << word_cnt << "\n";
	}

	return 0;
}