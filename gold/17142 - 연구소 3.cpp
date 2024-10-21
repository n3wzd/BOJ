#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
struct Point { int x, y; };
int N, M, V, E, minTime = 2502, board[51][51], dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };
Point virus[11];
bool selected[11], visited[51][51];

void BFS() {
    queue<Point> q;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < V; i++) {
        if (selected[i]) {
            q.push(virus[i]);
            visited[virus[i].y][virus[i].x] = 1;
        }
    }

    int emptyCnt = 0, gameTime = 0;
    while (emptyCnt < E) {
        if (q.empty())
            return;
        int size = q.size();
        while (size--) {
            Point p = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = p.x + dx[d], ny = p.y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N || board[ny][nx] == 1 || visited[ny][nx])
                    continue;
                if (board[ny][nx] == 0)
                    emptyCnt++;
                visited[ny][nx] = 1;
                q.push({ nx, ny });
            }
        }
        gameTime++;
    }
    minTime = min(minTime, gameTime);
}

void searchVirus(int depth, int start) {
    if (depth == M) {
        BFS();
        return;
    }
    for (int i = start; i < V; i++) {
        selected[i] = 1;
        searchVirus(depth + 1, i + 1);
        selected[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> board[y][x];
            if (board[y][x] == 2)
                virus[V++] = { x, y };
            if (board[y][x] == 0)
                E++;
        }
    }
    searchVirus(0, 0);
    cout << (minTime == 2502 ? -1 : minTime);
    return 0;
}
