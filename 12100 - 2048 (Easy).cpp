#include <iostream>
#include <cstring>
using namespace std;
struct Point { int x, y; };
struct Group { int size = 0, rainbow = 0, x = 21, y = 21; };
int N, M, score, dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
int board[21][21], boardTmp[21][21], visited[21][21];

void gameDFS(int x, int y, int id, Group& group) {
    group.size++;
    if (board[y][x] == 0)
        group.rainbow++;
    else if (board[y][x] > 0) {
        if (y < group.y || (y == group.y && x < group.x))
            group.x = x, group.y = y;
    }
    visited[y][x] = id;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] == id)
            continue;
        if (board[ny][nx] == id || board[ny][nx] == 0)
            gameDFS(nx, ny, id, group);
    }
}

void eraseDFS(int x, int y, int id) {
    visited[y][x] = 0;
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N || visited[ny][nx] == 0)
            continue;
        if (board[ny][nx] == id || board[ny][nx] == 0)
            eraseDFS(nx, ny, id);
    }
    board[y][x] = -2;
}

bool game() {
    Group maxGroup;
    memset(visited, 0, sizeof(visited));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (visited[y][x] || board[y][x] <= 0)
                continue;
            Group group; gameDFS(x, y, board[y][x], group);
            if (group.size > maxGroup.size && group.size >= 2)
                maxGroup = group;
            else if (group.size == maxGroup.size) {
                if (group.rainbow > maxGroup.rainbow)
                    maxGroup = group;
                else if (group.rainbow == maxGroup.rainbow) {
                    if (group.y > maxGroup.y || (group.y == maxGroup.y && group.x > maxGroup.x))
                        maxGroup = group;
                }
            }
        }
    }
    if (maxGroup.size > 0) {
        eraseDFS(maxGroup.x, maxGroup.y, board[maxGroup.y][maxGroup.x]);
        score += maxGroup.size * maxGroup.size;
        return 1;
    }
    else
        return 0;
}

void move(int x, int y, int id) {
    if (board[y][x] <= -1)
        return;
    board[y][x] = -2;
    while (y < N - 1 && board[y + 1][x] == -2) y++;
    board[y][x] = id;
}

void gravity() {
    for (int y = N - 1; y >= 0; y--)
        for (int x = 0; x < N; x++)
            move(x, y, board[y][x]);
}

void rotate(int x, int y) {
    bool even = N % 2 == 0; int c = even ? N / 2 - 1 : N / 2;
    int dx = x - c + (even && x <= c ? -1 : 0), dy = y - c + (even && y <= c ? -1 : 0);
    int nx = c + dy, ny = c - dx;
    boardTmp[ny + (even && ny <= c ? 1 : 0)][nx + (even && nx <= c ? 1 : 0)] = board[y][x];
}

void rotateAll() {
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            rotate(x, y);
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            board[y][x] = boardTmp[y][x];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    while (game()) {
        gravity();
        rotateAll();
        gravity();
    }
    cout << score;
    return 0;
}
