#include <iostream>
#include <cstring>
using namespace std;
struct Board { int value, score; };
int N, M, diceX, diceY, K, Dc = 0, Dl = 3, Du = 1, moveDire, gameScore;
int sym[6] = { 5, 4, 3, 2, 1, 0 }, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
Board board[21][21];
bool visited[21][21];

int DFS1(int x, int y) {
    visited[y][x] = 1;
    int cnt = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx] || board[y][x].value != board[ny][nx].value))
            cnt += DFS1(nx, ny);
    }
    return cnt;
}

void DFS2(int x, int y, int score) {
    visited[y][x] = 1;
    board[y][x].score = score;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (!(nx < 0 || nx >= M || ny < 0 || ny >= N || visited[ny][nx] || board[y][x].value != board[ny][nx].value))
            DFS2(nx, ny, score);
    }
}

void updateBoardScore() {
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (!visited[y][x])
                board[y][x].score = DFS1(x, y) * board[y][x].value;
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            if (!visited[y][x])
                DFS2(x, y, board[y][x].score);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < M; x++)
            cin >> board[y][x].value;
    updateBoardScore();
    while (K--) {
        int nx = diceX + dx[moveDire], ny = diceY + dy[moveDire];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N) {
            moveDire = (moveDire + 2) % 4;
            nx = diceX + dx[moveDire], ny = diceY + dy[moveDire];
        }
        diceX = nx, diceY = ny;
        if (moveDire == 0) {
            int tmp = sym[Dc];
            Dc = Dl; Dl = tmp;
        }
        if (moveDire == 2) {
            int tmp = sym[Dl];
            Dl = Dc; Dc = tmp;
        }
        if (moveDire == 3) {
            int tmp = sym[Du];
            Du = Dc; Dc = tmp;
        }
        if (moveDire == 1) {
            int tmp = sym[Dc];
            Dc = Du; Du = tmp;
        }
        if (sym[Dc] + 1 > board[diceY][diceX].value)
            moveDire = (moveDire + 1) % 4;
        else if (sym[Dc] + 1 < board[diceY][diceX].value)
            moveDire = (moveDire + 3) % 4;
        gameScore += board[diceY][diceX].score;
    }
    cout << gameScore;
    return 0;
}
