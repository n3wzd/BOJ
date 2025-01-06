#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Point { int x, y; };
struct Node { int x, y, r; };
int dist[51][51][4], N, dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1}; bool isEnd = 0;
vector<string> maps(50);
vector<Point> goals, mirrors;
queue<Node> q;

void ray(int x, int y, int r, int d) {
    while (x >= 0 && x < N && y >= 0 && y < N && maps[y][x] != '*') {
        if (x == goals[1].x && y == goals[1].y) {
            isEnd = 1;
            return;
        }
        if (maps[y][x] == '!' && dist[y][x][r] == 0) {
            q.push({ x, y, r });
            dist[y][x][r] = d + 1;
        }
        x += dx[r], y += dy[r];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int y = 0; y < N; y++) {
        cin >> maps[y];
        for (int x = 0; x < N; x++) {
            if (maps[y][x] == '#')
                goals.push_back({ x, y });
            if (maps[y][x] == '!')
                mirrors.push_back({ x, y });
        }
    }
    for(int r = 0; r < 4; r++)
        ray(goals[0].x, goals[0].y, r, 0);
    if (isEnd) {
        cout << 0;
        return 0;
    }
    while(!q.empty()) {
        auto cur = q.front(); q.pop();
        int x = cur.x, y = cur.y, r = cur.r, d = dist[y][x][r];
        ray(x, y, (r + 1) % 4, d); ray(x, y, (r + 3) % 4, d);
        if (isEnd) {
            cout << dist[y][x][r];
            return 0;
        }
    }
    return 0;
}
