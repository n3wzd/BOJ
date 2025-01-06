#include <iostream>
using namespace std;
struct Player { int pos = 0, branch = 0; };
struct Board { int score = 0, id = 0; };
int dice[11], branchPoint[4] = { 0, 5, 10, 15 }, boardLimit[4] = { 21, 13, 17, 23 };
Board board[4][23];
Player player[4];

void init() {
	Board boardData1[8] = { { 10, 5 }, { 13, 21 }, { 16, 22 }, { 19, 23 }, { 25, 29 }, { 30, 30 }, { 35, 31 }, { 40, 20 } };
	Board boardData2[7] = { { 20, 10 }, { 22, 24 }, { 24, 25 }, { 25, 29 }, { 30, 30 }, { 35, 31 }, { 40, 20 } };
	Board boardData3[8] = { { 30, 15 }, { 28, 26 }, { 27, 27 }, { 26, 28 }, { 25, 29 }, { 30, 30 }, { 35, 31 }, { 40, 20 } };
	for (int i = 0; i < boardLimit[0]; i++)
		board[0][i] = { i * 2, i };
	for (int i = branchPoint[1]; i < boardLimit[1]; i++)
		board[1][i] = boardData1[i - branchPoint[1]];
	for (int i = branchPoint[2]; i < boardLimit[2]; i++)
		board[2][i] = boardData2[i - branchPoint[2]];
	for (int i = branchPoint[3]; i < boardLimit[3]; i++)
		board[3][i] = boardData3[i - branchPoint[3]];
}

bool canMove(int id) {
	bool block = 0;
	for (int i = 0; i < 4; i++)
		if (i != id && player[i].pos < boardLimit[player[i].branch])
			block |= (board[player[id].branch][player[id].pos].id == board[player[i].branch][player[i].pos].id);
	return !block;
}

int game(int turn = 0) {
	if (turn >= 10)
		return 0;

	int score = 0;
	for (int i = 0; i < 4; i++) {
		if (player[i].pos >= boardLimit[player[i].branch])
			continue;

		Player backupPlayer = player[i];
		player[i].pos += dice[turn];
		for (int b = 1; b <= 3; b++)
			if (player[i].branch == 0 && player[i].pos == branchPoint[b])
				player[i].branch = b;

		int brc = player[i].branch, pos = player[i].pos;
		if (pos < boardLimit[brc]) {
			if (canMove(i))
				score = max(score, game(turn + 1) + board[brc][pos].score);
		}
		else
			score = max(score, game(turn + 1));
		player[i] = backupPlayer;
	}
	return score;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		cin >> dice[i];
	init();
	cout << game();
	return 0;
}
