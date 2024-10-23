#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Board { int heat = 0; bool wall[4] = { 0, 0, 0, 0 }; };
struct Point { int x, y; };
struct Heater { int dire;  Point p; };
int R, C, K, W, choco, boardTmp[21][21], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 }, inToHD[4] = { 0, 2, 3, 1 };
Board board[21][21];
vector<Heater> heaters; vector<Point> searchs;

void heatDFS(int x, int y, int d, int level, bool mode) {
    if (x < 0 || x >= C || y < 0 || y >= R || level == 0 || board[y][x].wall[(d + 2) % 4])
        return;
    if (mode == 0)
        boardTmp[y][x] = 1;
    else {
        if (boardTmp[y][x] == 1) {
            board[y][x].heat += level;
            boardTmp[y][x] = 0;
        }
    }
    int dv = (d + 1) % 4;
    heatDFS(x + dx[d], y + dy[d], d, level - 1, mode);
    if (!board[y][x].wall[dv])
        heatDFS(x + dx[d] + dx[dv], y + dy[d] + dy[dv], d, level - 1, mode);
    if (!board[y][x].wall[(dv + 2) % 4])
        heatDFS(x + dx[d] - dx[dv], y + dy[d] - dy[dv], d, level - 1, mode);
}

void heatTime() {
    for (Heater heater : heaters) {
        int x = heater.p.x, y = heater.p.y, d = heater.dire;
        heatDFS(x + dx[d], y + dy[d], d, 5, 0);
        heatDFS(x + dx[d], y + dy[d], d, 5, 1);
    }
}

void convection(int x, int y) {
    for (int d = 0; d < 4; d++) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= C || ny < 0 || ny >= R || board[y][x].wall[d])
            continue;
        int diff = (board[y][x].heat - board[ny][nx].heat) / 4;
        if (diff > 0) {
            boardTmp[y][x] -= diff;
            boardTmp[ny][nx] += diff;
        }
    }
}

void convectionAll() {
    for (int y = 0; y < R; y++)
        for (int x = 0; x < C; x++)
            convection(x, y);
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            board[y][x].heat += boardTmp[y][x];
            boardTmp[y][x] = 0;
        }
    }
}

void cold(int x, int y) {
    if (board[y][x].heat > 0)
        board[y][x].heat--;
}

void coldAll() {
    for (int x = 0; x < C - 1; x++)
        cold(x, 0);
    for (int y = 0; y < R - 1; y++)
        cold(C - 1, y);
    for (int x = C - 1; x > 0; x--)
        cold(x, R - 1);
    for (int y = R - 1; y > 0; y--)
        cold(0, y);
}

bool isEnd() {
    bool ok = 1;
    for (Point p : searchs)
        ok &= board[p.y][p.x].heat >= K;
    return ok;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            int h; cin >> h;
            if (h == 5)
                searchs.push_back({ x, y });
            else if (h != 0)
                heaters.push_back({ inToHD[h - 1], { x, y } });
        }
    }
    cin >> W;
    while (W--) {
        int x, y, t; cin >> y >> x >> t; y--, x--;
        if (t == 0) {
            board[y][x].wall[3] = 1;
            board[y - 1][x].wall[1] = 1;
        }
        else {
            board[y][x].wall[0] = 1;
            board[y][x + 1].wall[2] = 1;
        }
    }
    while (!isEnd() && choco <= 100) {
        heatTime();
        convectionAll();
        coldAll();
        choco++;
    }
    cout << choco;
    return 0;
}
