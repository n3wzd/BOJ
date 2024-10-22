#include <iostream>
using namespace std;
int N, K, gameTime, X1, Y1, board1[26][26], board2[26][26], bowl[102], bowlDx[102];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void makeBoard1() {
    int rem = N - 2, level = 4, x = 0, y = 0, genID = N, dire = 0;
    for (; rem - level / 2 >= 0; level++)
        rem -= level / 2;
    for (; x < rem; x++)
        board1[y][x] = genID--;
    x--, level--;
    while (genID > 0) {
        for (int i = 0; i < level / 2; i++) {
            x += dx[dire], y += dy[dire];
            board1[y][x] = genID--;
            X1 = max(x + 1, X1), Y1 = max(y + 1, Y1);
        }
        dire = (dire + 1) % 4;
        level--;
    }
}

void makeBoard2() {
    int genID = 1, len = N / 4;
    for (int x = 0; x < N / 4; x++)
        board2[1][x] = genID++;
    for (int x = len - 1; x >= 0; x--)
        board2[2][x] = genID++;
    for (int x = 0; x < N / 4; x++)
        board2[3][x] = genID++;
    for (int x = len - 1; x >= 0; x--)
        board2[0][x] = genID++;
}

bool finishBowl() {
    int minFish = 999999, maxFish = -1;
    for (int i = 1; i <= N; i++) {
        minFish = min(minFish, bowl[i]);
        maxFish = max(maxFish, bowl[i]);
    }
    return maxFish - minFish <= K;
}

void underdogBowl() {
    int minFish = 999999;
    for (int i = 1; i <= N; i++)
        minFish = min(minFish, bowl[i]);
    for (int i = 1; i <= N; i++)
        if (bowl[i] == minFish)
            bowl[i]++;
}

void matchingFish(int board[26][26], int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || ny < 0 || board[ny][nx] == 0)
            continue;
        int diff = (bowl[board[y][x]] - bowl[board[ny][nx]]) / 5;
        if (diff > 0) {
            bowlDx[board[ny][nx]] += diff;
            bowlDx[board[y][x]] -= diff;
        }
    }
}

void updateFish(int board[26][26], int X, int Y) {
    for (int y = 0; y < Y; y++)
        for (int x = 0; x < X; x++)
            if (board[y][x] != 0)
                matchingFish(board, x, y);
    for (int i = 1; i <= N; i++)
        bowl[i] += bowlDx[i];

    int genID = 1;
    for (int x = X - 1; x >= 0; x--)
        for (int y = 0; y < Y; y++)
            if (board[y][x] != 0)
                bowlDx[genID++] = bowl[board[y][x]];
    for (int i = 1; i <= N; i++) {
        bowl[i] = bowlDx[i];
        bowlDx[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> bowl[i];
    makeBoard1(); makeBoard2();
    while (!finishBowl()) {
        underdogBowl();
        updateFish(board1, X1, Y1);
        updateFish(board2, N / 4, 4);
        gameTime++;
    }
    cout << gameTime;
    return 0;
}
