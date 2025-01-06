#include <iostream>
using namespace std;
struct Wind { int dire, mass, per; };
int N, x, y, dire, outerSand;
int board[501][501];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
Wind wind[9] = { { 0, 2, 5 }, { 1, 1, 10 }, { 2, 1, 7 }, { 2, 2, 2 }, { 3, 1, 1 }, { 5, 1, 1 }, { 6, 1, 7 }, { 6, 2, 2 }, { 7, 1, 10 } };

void sandstorm() {
    int sand = board[y][x];
    for (int w = 0; w < 9; w++) {
        int nextDire = (dire + wind[w].dire) % 8;
        int nx = x + dx[nextDire] * wind[w].mass, ny = y + dy[nextDire] * wind[w].mass;
        int nextSand = board[y][x] * wind[w].per / 100;
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            outerSand += nextSand;
        else
            board[ny][nx] += nextSand;
        sand -= nextSand;
    }
    int nx = x + dx[dire], ny = y + dy[dire];
    if (nx < 0 || nx >= N || ny < 0 || ny >= N)
        outerSand += sand;
    else
        board[ny][nx] += sand;
}

void proceed(int dist) {
    for (int w = 1; w <= dist; w++) {
        x += dx[dire], y += dy[dire];
        sandstorm();
    }
    dire = (dire + 2) % 8;
}

void whirlwind() {
    for (int i = 1; i < N; i++)
        for (int t = 0; t < 2; t++)
            proceed(i);
    proceed(N - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N; x = N / 2, y = N / 2;
    for (int ty = 0; ty < N; ty++)
        for (int tx = 0; tx < N; tx++)
            cin >> board[ty][tx];
    whirlwind();
    cout << outerSand;
    return 0;
}
