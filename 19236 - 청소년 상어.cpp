#include <iostream>
using namespace std;
struct Shark { int id, dire; };
struct Point { int x, y; };
Shark board[4][4], boardBackup[4][4];
Point fishPos[17], fishPosBackup[17];
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 }, dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

void moveFish(int x, int y, int sharkX, int sharkY) {
    for (int dd = 0; dd < 8; dd++) {
        int d = (board[y][x].dire + dd) % 8;
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= 4 || ny < 0 || ny >= 4 || (nx == sharkX && ny == sharkY))
            continue;

        board[y][x].dire = d;
        Shark tmp = board[ny][nx];
        board[ny][nx] = board[y][x];
        board[y][x] = tmp;
        fishPos[board[ny][nx].id] = { nx, ny };
        fishPos[board[y][x].id] = { x, y };
        break;
    }
}

int quest(int x = 0, int y = 0) {
    int score = 0;
    if (x >= 0 && x < 4 && y >= 0 && y < 4 && board[y][x].id > 0) {
        Shark boardBackup[4][4];
        Point fishPosBackup[17];
        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                boardBackup[y][x] = board[y][x];
        for (int i = 1; i <= 16; i++)
            fishPosBackup[i] = fishPos[i];

        int newDire = board[y][x].dire;
        score += board[y][x].id;
        fishPos[board[y][x].id] = { -1, -1 };
        board[y][x].id = 0;
        for (int i = 1; i <= 16; i++)
            if (fishPos[i].x != -1)
                moveFish(fishPos[i].x, fishPos[i].y, x, y);

        int moreScore = 0;
        for (int dist = 1; dist < 4; dist++)
            moreScore = max(moreScore, quest(x + dx[newDire] * dist, y + dy[newDire] * dist));
        score += moreScore;

        for (int y = 0; y < 4; y++)
            for (int x = 0; x < 4; x++)
                board[y][x] = boardBackup[y][x];
        for (int i = 1; i <= 16; i++)
            fishPos[i] = fishPosBackup[i];
    }
    return score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            cin >> board[y][x].id >> board[y][x].dire;
            board[y][x].dire--;
            fishPos[board[y][x].id] = { x, y };
        }
    }
    cout << quest();
    return 0;
}
