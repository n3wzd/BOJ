#include <iostream>
#include <cmath>
using namespace std;
int N, Q, L, PN, board[66][66], boardTmp[66][66];
bool visited[66][66];
int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

void rotateSingle(int x, int y, int cx, int cy) {
    int ax = x - cx + (x <= cx ? -1 : 0), ay = y - cy + (y <= cy ? -1 : 0);
    int nx = cx - ay, ny = cy + ax;
    boardTmp[ny + (ny <= cy ? 1 : 0)][nx + (nx <= cx ? 1 : 0)] = board[y][x];
}

void rotate(int sx, int sy, int size) {
    if (size == 1)
        return;
    for (int y = sy; y < sy + size; y++)
        for (int x = sx; x < sx + size; x++)
            rotateSingle(x, y, sx + size / 2 - 1, sy + size / 2 - 1);
    for (int y = sy; y < sy + size; y++)
        for (int x = sx; x < sx + size; x++)
            board[y][x] = boardTmp[y][x];
}

void meltdown() {
    for (int y = 0; y < PN; y++) {
        for (int x = 0; x < PN; x++) {
            int cnt = 0;
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < PN && ny >= 0 && ny < PN && board[ny][nx] > 0)
                    cnt++;
            }
            boardTmp[y][x] = cnt;
        }
    }
    for (int y = 0; y < PN; y++)
        for (int x = 0; x < PN; x++)
            board[y][x] = max(board[y][x] + (boardTmp[y][x] < 3 ? -1 : 0), 0);
}

int sumAll() {
    int sum = 0;
    for (int y = 0; y < PN; y++)
        for (int x = 0; x < PN; x++)
            sum += board[y][x];
    return sum;
}

int DFS(int x, int y) {
    visited[y][x] = 1;
    int size = 1;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx >= 0 && nx < PN && ny >= 0 && ny < PN && board[ny][nx] > 0 && !visited[ny][nx])
            size += DFS(nx, ny);
    }
    return size;
}

int maxIceberg() {
    int iceberg = 0;
    for (int y = 0; y < PN; y++)
        for (int x = 0; x < PN; x++)
            if (board[y][x] > 0 && !visited[y][x])
                iceberg = max(iceberg, DFS(x, y));
    return iceberg;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q; PN = pow(2, N);
    for (int y = 0; y < PN; y++)
        for (int x = 0; x < PN; x++)
            cin >> board[y][x];
    while (Q--) {
        cin >> L;
        int level = pow(2, L);
        for (int y = 0; y < PN; y += level)
            for (int x = 0; x < PN; x += level)
                rotate(x, y, level);
        meltdown();
    }
    cout << sumAll() << "\n" << maxIceberg();
    return 0;
}
