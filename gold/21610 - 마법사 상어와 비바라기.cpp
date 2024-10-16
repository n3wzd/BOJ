#include <iostream>
#include <queue>
using namespace std;
struct Cloud { int x, y; };
int N, M, board[52][52];
bool hasCloud[52][52];
int dx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 }, dy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
queue<Cloud> clouds;

void waterCopyBug(int x, int y) {
    for (int d = 1; d < 8; d += 2) {
        int nx = x + dx[d], ny = y + dy[d];
        if (nx < 0 || nx >= N || ny < 0 || ny >= N)
            continue;
        board[y][x] += board[ny][nx] > 0 ? 1 : 0;
    }
}

void rainMagic(int d, int s) {
    int size = clouds.size();
    while (size--) {
        Cloud c = clouds.front(); clouds.pop();
        c.x = (c.x + (dx[d] + N) * s) % N, c.y = (c.y + (dy[d] + N) * s) % N;
        board[c.y][c.x]++;
        hasCloud[c.y][c.x] = 1;
        clouds.push(c);
    }

    while (!clouds.empty()) {
        Cloud c = clouds.front(); clouds.pop();
        waterCopyBug(c.x, c.y);
    }

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (board[y][x] >= 2 && !hasCloud[y][x]) {
                clouds.push({ x, y });
                board[y][x] -= 2;
            }
            hasCloud[y][x] = 0;
        }
    }
}

int sumAll() {
    int sum = 0;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            sum += board[y][x];
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            cin >> board[y][x];
    clouds.push({ 0, N - 2 }); clouds.push({ 1, N - 2 });
    clouds.push({ 0, N - 1 }); clouds.push({ 1, N - 1 });
    while (M--) {
        int d, s;
        cin >> d >> s;
        rainMagic(d - 1, s);
    }
    cout << sumAll();
    return 0;
}
