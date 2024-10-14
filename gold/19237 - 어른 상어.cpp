#include <iostream>
using namespace std;
struct Shark { int x, y, dire, direOrder[4][4], isDead; };
struct Board { int sharkId = 0, markId = 0, markTime = 0; };
struct Point { int x, y; };
int N, M, K, gameTime, remain;
Shark sharkList[402];
Board board[21][21];
int dx[4] = { 0, 0, -1, 1 }, dy[4] = { -1, 1, 0, 0 };

bool sharkTime() {
    for (int i = 1; i <= M; i++) {
        if (!sharkList[i].isDead) {
            int x = sharkList[i].x, y = sharkList[i].y;
            board[y][x].markTime = gameTime + K;
            board[y][x].markId = i;
        }
    }

    for (int i = 1; i <= M; i++) {
        if (sharkList[i].isDead)
            continue;

        bool isMoved = 0;
        for (int d = 0; d < 4; d++) {
            int x = sharkList[i].x, y = sharkList[i].y;
            int nextDire = sharkList[i].direOrder[sharkList[i].dire][d];
            int nx = x + dx[nextDire], ny = y + dy[nextDire];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N || gameTime < board[ny][nx].markTime)
                continue;

            board[y][x].sharkId = 0;
            if (board[ny][nx].sharkId != 0 && board[ny][nx].sharkId < i) {
                sharkList[i].isDead = 1;
                remain--;
            }
            else {
                board[ny][nx].sharkId = i;
                sharkList[i].x = nx, sharkList[i].y = ny;
                sharkList[i].dire = nextDire;
            }
            isMoved = 1;
            break;
        }

        if (!isMoved) {
            for (int d = 0; d < 4; d++) {
                int x = sharkList[i].x, y = sharkList[i].y;
                int nextDire = sharkList[i].direOrder[sharkList[i].dire][d];
                int nx = x + dx[nextDire], ny = y + dy[nextDire];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[ny][nx].markId != i)
                    continue;

                board[y][x].sharkId = 0;
                board[ny][nx].sharkId = i;
                sharkList[i].x = nx, sharkList[i].y = ny;
                sharkList[i].dire = nextDire;
                break;
            }
        }
    }

    gameTime++;
    return (remain <= 1 || gameTime > 1000);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    remain = M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int i;
            cin >> i;
            board[y][x].sharkId = i;
            sharkList[i].x = x, sharkList[i].y = y;
        }
    }
    for (int i = 1; i <= M; i++) {
        cin >> sharkList[i].dire;
        sharkList[i].dire--;
        sharkList[i].isDead = 0;
    }
    for (int i = 1; i <= M; i++) {
        for (int d = 0; d < 4; d++) {
            for (int c = 0; c < 4; c++) {
                cin >> sharkList[i].direOrder[d][c];
                sharkList[i].direOrder[d][c]--;
            }
        }
    }
    while (!sharkTime());
    cout << (gameTime > 1000 ? -1 : gameTime);
    return 0;
}
